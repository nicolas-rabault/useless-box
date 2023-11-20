/******************************************************************************
 * @file useless_behavior
 * @brief driver example a simple button
 * @author Luos
 * @version 0.0.0
 ******************************************************************************/

#include "luos_engine.h"
#include "useless_behavior.h"
#include "useless_moves.h"
#include <stdlib.h>

/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define INIT_TIME    150
#define USELESS_TYPE LUOS_LAST_TYPE

typedef enum
{
    HATCH,
    FINGER,
    BONUS_HATCH,
    USELESS_MOTOR_NB
} motors_t;

typedef struct
{
    // In this struct we save all the informations we need to properly play an animation
    bool is_playing;
    uint32_t last_frame_time;
    uint32_t last_frame_number;
    const useless_move_t *move;
} useless_anim_t;

static void Useless_MsgHandler(service_t *service, const msg_t *msg);
static void Set(uint8_t ratio, uint16_t to);
static void PickRandomMove(void);
void PickRandomRangeMove(void);
static void PlayAnimation(void);
static void PlayRangeAnimation(void);

/*******************************************************************************
 * Variables
 ******************************************************************************/
service_t *useless_service;
uint16_t useless_motor[USELESS_MOTOR_NB]                           = {0};
uint16_t led_id                                                    = 0;
bool button_state                                                  = false;
bool distance_state                                                = false;
uint32_t moves_priority_sum                                        = 0;
uint32_t range_moves_priority_sum                                  = 0;
useless_anim_t useless_anim                                        = {.is_playing = false, .last_frame_time = 0, .last_frame_number = 0, .move = NULL};
useless_anim_t useless_range_anim                                  = {.is_playing = false, .last_frame_time = 0, .last_frame_number = 0, .move = NULL};
const angular_position_t useless_motor_max_angle[USELESS_MOTOR_NB] = {
    {.raw = HATCH_MAX_ANGLE},
    {.raw = FINGER_MAX_ANGLE},
    {.raw = BONUS_HATCH_MAX_ANGLE},
};
const angular_position_t useless_motor_min_angle[USELESS_MOTOR_NB] = {
    {.raw = HATCH_MIN_ANGLE},
    {.raw = FINGER_MIN_ANGLE},
    {.raw = BONUS_HATCH_MIN_ANGLE},
};

/*******************************************************************************
 * Functions
 ******************************************************************************/

/******************************************************************************
 * @brief init must be call in project init
 * @param None
 * @return None
 ******************************************************************************/
void Useless_Init(void)
{
    // service initialization
    revision_t useless_revision = {.major = 1, .minor = 0, .build = 0};
    // Service creation
    useless_service = Luos_CreateService(Useless_MsgHandler, USELESS_TYPE, "useless_service", useless_revision);

    // Compute the sum of all the moves priority. This will allow us to choose a random move later.
    for (uint16_t i = 0; i < sizeof(useless_moves) / sizeof(useless_move_t); i++)
    {
        moves_priority_sum += useless_moves[i].priority;
    }
    for (uint16_t i = 0; i < sizeof(useless_range_moves) / sizeof(useless_move_t); i++)
    {
        range_moves_priority_sum += useless_range_moves[i].priority;
    }

    // Wait for service to be ready to use before sending detection
    uint32_t init_timer = Luos_GetSystick();
    while (Luos_GetSystick() - init_timer < INIT_TIME)
        ;
    // Detect all services on the network
    Luos_Detect(useless_service);
}

/******************************************************************************
 * @brief loop must be call in project loop
 * @param None
 * @return None
 ******************************************************************************/
void Useless_Loop(void)
{
    if (useless_anim.is_playing)
    {
        // We are playing an animation, let' continue it.
        PlayAnimation();
        return;
    }
    // No animation is playing, let's check if the button is pressed.
    if (button_state == STATE_WRONG)
    {
        // The button is pressed, let's play a random animation.
        PickRandomMove();
        return;
    }
    if (useless_range_anim.is_playing)
    {
        // We are playing a range animation, let' continue it.
        PlayRangeAnimation();
        return;
    }
    // No animation is playing and the button is not pressed, let's check if we see something close.
    if (distance_state == STATE_WRONG)
    {
        // We see something close, let's play a random animation.
        PickRandomRangeMove();
        return;
    }
}

/******************************************************************************
 * @brief Msg Handler is called back when a msg is receive for this useless service
 * @param Service destination (our useless service)
 * @param Msg receive (our useless msg)
 * @return None
 ******************************************************************************/
void Useless_MsgHandler(service_t *service, const msg_t *msg)
{
    if (msg->header.cmd == END_DETECTION)
    {
        // We just finished the detection, we should have all the services on our routing table. Let's configure them.

        //****************************************************************
        // ********* STEP 1 : Find the motors we want to control *********
        // We can find them and save there service ID to easily reach them later.
        search_result_t result;
        RTFilter_Alias(RTFilter_Reset(&result), "hatch");
        if (result.result_nbr > 0)
        {
            // We found a motor named "hatch" on the network, we save its service ID
            useless_motor[HATCH] = result.result_table[0]->id;
        }
        else
        {
            LUOS_ASSERT(0); // we can't do anything without a hatch, let's crash.
        }
        RTFilter_Alias(RTFilter_Reset(&result), "finger");
        if (result.result_nbr > 0)
        {
            // We found a motor named "finger" on the network, we save its service ID
            useless_motor[FINGER] = result.result_table[0]->id;
        }
        else
        {
            LUOS_ASSERT(0); // we can't do anything without a finger, let's crash.
        }
        RTFilter_Alias(RTFilter_Reset(&result), "bonus_hatch");
        if (result.result_nbr > 0)
        {
            // We found a motor named "bonus_hatch" on the network, we save its service ID
            useless_motor[BONUS_HATCH] = result.result_table[0]->id;
        } // We can survive without a bonus_hatch...

        //***********************************************************************************
        // ********* STEP 2 : Configure the button to send us an updates every 20ms *********
        // We want to be notified when the button state change, so we ask the button to send us its state every 20ms (BTW, 20ms is the max refresh rate of the motors, that is why I choose this value.)
        RTFilter_Alias(RTFilter_Reset(&result), "button");
        if (result.result_nbr > 0)
        {
            // We found the button on the network!
            msg_t msg;
            msg.header.target      = result.result_table[0]->id;
            msg.header.target_mode = SERVICEIDACK;
            // Setup auto update each 20ms on button
            time_luos_t time = TimeOD_TimeFrom_ms(20.0f);
            TimeOD_TimeToMsg(&time, &msg);
            msg.header.cmd = UPDATE_PUB;
            Luos_SendMsg(useless_service, &msg);
        }
        else
        {
            LUOS_ASSERT(0); // we can't do anything without a button, let's crash.
        }

        //***********************************************************************
        // ********* STEP 3 : Configure the distance sensor and the led *********
        RTFilter_Alias(RTFilter_Reset(&result), "distance");
        if (result.result_nbr > 0)
        {
            // We found a distance sensor named "distance" on the network!
            msg_t msg;
            msg.header.target      = result.result_table[0]->id;
            msg.header.target_mode = SERVICEIDACK;
            // Setup auto update each 20ms on distance
            time_luos_t time = TimeOD_TimeFrom_ms(20.0f);
            TimeOD_TimeToMsg(&time, &msg);
            msg.header.cmd = UPDATE_PUB;
            Luos_SendMsg(useless_service, &msg);
        } // We can survive without a distance sensor...
        RTFilter_Alias(RTFilter_Reset(&result), "led");
        if (result.result_nbr > 0)
        {
            // We found a led named "led" on the network, we save its service ID
            led_id = result.result_table[0]->id;
        } // We can survive without a led...
    }

    if (msg->header.cmd == IO_STATE)
    {
        // This message may come from the button. This is the 20ms update we asked for in the detection.
        button_state = (bool)msg->data[0];
    }

    if (msg->header.cmd == LINEAR_POSITION)
    {
        // This message may com from the distance sensor. This is the 20ms update we asked for in the detection.
        linear_position_t distance;
        LinearOD_PositionFromMsg(&distance, msg);
        if ((distance.raw < 0.0) || (distance.raw > 0.2))
        {
            // The distance sensor don't see anything close.
            distance_state = STATE_RIGHT;
        }
        else
        {
            // The distance sensor see something close.
            distance_state = STATE_WRONG;
        }
    }

    // We probably don't want to do anything more here, except if we want to get some information for a computer at some points...
}

/******************************************************************************
 * @brief Send a specific angle to a specific useless motor
 * @param angle : angle to send
 * @param to : useless motor to send the angle to
 * @return None
 ******************************************************************************/
void Set(uint8_t ratio, uint16_t to)
{
    if (useless_motor[to] == 0)
    {
        // The bonus_hatch motor is not mandatory, so we check if it's present before sending it a message
        return;
    }
    angular_position_t angle;
    angle.raw = (useless_motor_min_angle[to].raw + ((useless_motor_max_angle[to].raw - useless_motor_min_angle[to].raw) * ((float)ratio / 100.0f)));
    msg_t msg;
    msg.header.target_mode = SERVICEIDACK;
    msg.header.target      = useless_motor[to];
    msg.header.cmd         = ANGULAR_POSITION;
    AngularOD_PositionToMsg(&angle, &msg);
    Luos_SendMsg(useless_service, &msg);
}

/******************************************************************************
 * @brief Pick a useless animation based on theire priority in the list
 * @param None
 * @return None
 ******************************************************************************/
void PickRandomMove(void)
{
    // This function will choose a random move to play, based on the priority of each move.
    uint16_t random_number = rand() % moves_priority_sum;
    uint16_t current_sum   = 0;
    for (uint16_t i = 0; i < sizeof(useless_moves) / sizeof(useless_move_t); i++)
    {
        current_sum += useless_moves[i].priority;
        if (random_number < current_sum)
        {
            // We found the move we want to play, let's save it in the useless_anim struct
            useless_anim.is_playing        = true; // We pick it so let's play it!
            useless_anim.last_frame_number = 0;
            useless_anim.move              = &useless_moves[i];
            return;
        }
    }
}

/******************************************************************************
 * @brief Pick a useless range animation based on theire priority in the list
 * @param None
 * @return None
 ******************************************************************************/
void PickRandomRangeMove(void)
{
    // This function will choose a random move to play, based on the priority of each move.
    uint16_t random_number = rand() % range_moves_priority_sum;
    uint16_t current_sum   = 0;
    for (uint16_t i = 0; i < sizeof(useless_range_moves) / sizeof(useless_move_t); i++)
    {
        current_sum += useless_range_moves[i].priority;
        if (random_number < current_sum)
        {
            // We found the move we want to play, let's save it in the useless_range_anim struct
            useless_range_anim.is_playing        = true; // We pick it so let's play it!
            useless_range_anim.last_frame_number = 0;
            useless_range_anim.move              = &useless_range_moves[i];
            return;
        }
    }
}

/******************************************************************************
 * @brief Play the current animation
 * @param None
 * @return None
 ******************************************************************************/
void PlayAnimation(void)
{
    static int8_t direction = 1;
    // Make sure to stop the range animation.
    useless_range_anim.is_playing = false;

    // This function will play the current animation, frame by frame.
    if (useless_anim.last_frame_number >= useless_anim.move->frame_number)
    {
        // We finished the animation, let's stop it.
        useless_anim.is_playing = false;
        return;
    }
    // We are still playing the animation, let's continue it.
    uint32_t current_time = Luos_GetSystick();
    if ((current_time - useless_anim.last_frame_time) > 20) // We send a new frame every 20ms
    {
        // It's time to play the next frame
        useless_anim.last_frame_time = current_time;
        // We send the next frame to each motor
        for (uint16_t i = 0; i < USELESS_MOTOR_NB; i++)
        {
            Set(useless_anim.move->frames[useless_anim.last_frame_number].ratios[i], i);
        }
        // We send the sext frame to the led
        uint8_t led_frame_state    = useless_anim.move->frames[useless_anim.last_frame_number].expected_state & (1 << STATE_LED);
        uint8_t button_frame_state = useless_anim.move->frames[useless_anim.last_frame_number].expected_state & 0x03;
        if (led_id)
        {
            msg_t msg;
            msg.header.target_mode = SERVICEIDACK;
            msg.header.target      = led_id;
            msg.header.cmd         = IO_STATE;
            msg.data[0]            = led_frame_state > 0;
            Luos_SendMsg(useless_service, &msg);
        }
        // Check if we need to change the direction of the animation
        if ((button_frame_state != button_state) && (button_frame_state != STATE_UNKNOWN))
        {
            // The button state is not the one we expected, let's play the animation backward.
            direction = -1;
        }
        if ((button_frame_state == button_state) && (button_frame_state != STATE_UNKNOWN))
        {
            // The button state is the one we expected, let's play the animation forward.
            direction = 1;
        }
        useless_anim.last_frame_number += direction;
    }
}

/******************************************************************************
 * @brief Play the current range animation
 * @param None
 * @return None
 ******************************************************************************/
void PlayRangeAnimation(void)
{
    static int8_t direction = 1;
    // This function will play the current animation, frame by frame.
    if (useless_range_anim.last_frame_number >= useless_range_anim.move->frame_number)
    {
        // We finished the animation, let's stop it.
        useless_range_anim.is_playing = false;
        return;
    }
    // We are still playing the animation, let's continue it.
    uint32_t current_time = Luos_GetSystick();
    if ((current_time - useless_range_anim.last_frame_time) > 20) // We send a new frame every 20ms
    {
        // It's time to play the next frame
        useless_range_anim.last_frame_time = current_time;
        // We send the next frame to each motor
        for (uint16_t i = 0; i < USELESS_MOTOR_NB; i++)
        {
            Set(useless_range_anim.move->frames[useless_range_anim.last_frame_number].ratios[i], i);
        }
        // We send the sext frame to the led
        uint8_t led_frame_state      = useless_range_anim.move->frames[useless_range_anim.last_frame_number].expected_state & (1 << STATE_LED);
        uint8_t distance_frame_state = useless_range_anim.move->frames[useless_range_anim.last_frame_number].expected_state & 0x03;
        if (led_id)
        {
            msg_t msg;
            msg.header.target_mode = SERVICEIDACK;
            msg.header.target      = led_id;
            msg.header.cmd         = IO_STATE;
            msg.header.size        = sizeof(char);
            msg.data[0]            = led_frame_state > 0;
            Luos_SendMsg(useless_service, &msg);
        }
        // Check if we need to change the direction of the animation
        if ((distance_frame_state != distance_state) && (distance_frame_state != STATE_UNKNOWN))
        {
            // The button state is not the one we expected, let's play the animation backward.
            direction = -1;
        }
        if ((distance_frame_state == distance_state) && (distance_frame_state != STATE_UNKNOWN))
        {
            // The button state is the one we expected, let's play the animation forward.
            direction = 1;
        }
        useless_range_anim.last_frame_number += direction;
    }
}
