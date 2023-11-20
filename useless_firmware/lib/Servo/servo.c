/******************************************************************************
 * @file servo
 * @brief driver example a simple servo motor
 * @author Luos
 * @version 0.0.0
 ******************************************************************************/
#include "servo_drv.h"
#include "stdint.h"

#include "servo.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/
static service_t *service_servo[SERVONUMBER]; // services table
servo_t servo[SERVONUMBER];                   // motor table
/*******************************************************************************
 * Function
 ******************************************************************************/
static void Servo_MsgHandler(service_t *service, const msg_t *msg);

/******************************************************************************
 * @brief init must be call in project init
 * @param None
 * @return None
 ******************************************************************************/
void Servo_Init(void)
{
    revision_t revision = {.major = 1, .minor = 0, .build = 0};

    Servo_DRVInit(servo);

    service_servo[0]               = Luos_CreateService(Servo_MsgHandler, ANGLE_TYPE, "hatch", revision);
    service_servo[0]->user_context = (void *)&servo[0];
    service_servo[1]               = Luos_CreateService(Servo_MsgHandler, ANGLE_TYPE, "finger", revision);
    service_servo[1]->user_context = (void *)&servo[1];
    service_servo[2]               = Luos_CreateService(Servo_MsgHandler, ANGLE_TYPE, "bonus_hatch", revision);
    service_servo[2]->user_context = (void *)&servo[2];
}
/******************************************************************************
 * @brief loop must be call in project loop
 * @param None
 * @return None
 ******************************************************************************/
void Servo_Loop(void)
{
}
/******************************************************************************
 * @brief Msg Handler call back when a msg receive for this service
 * @param Service destination
 * @param Msg receive
 * @return None
 ******************************************************************************/
static void Servo_MsgHandler(service_t *service, const msg_t *msg)
{
    servo_t *servo = (servo_t *)service->user_context;
    if (msg->header.cmd == ANGULAR_POSITION)
    {
        // set the motor position
        AngularOD_PositionFromMsg((angular_position_t *)&servo->angle, msg);
        if ((uintptr_t)service == (uintptr_t)service_servo[1])
        {
            // The motor we are moving is the finger, we need to be sure that the hatch is open to avoid breaking anything
            servo_t *hatch_servo = (servo_t *)service_servo[0]->user_context;
            if ((AngularOD_PositionTo_deg(servo->angle) > FINGER_REACH_HATCH) && (AngularOD_PositionTo_deg(hatch_servo->angle) < HATCH_MIN_OPEN))
            {
                // The hatch is not enought opened, we need to open it
                hatch_servo->angle = AngularOD_PositionFrom_deg(HATCH_MIN_OPEN);
                Servo_DRVSetPosition(hatch_servo);
            }
        }
        Servo_DRVSetPosition(servo);
    }
    else if (msg->header.cmd == PARAMETERS)
    {
        // set the servo parameters
        memcpy((void *)servo->param.unmap, msg->data, sizeof(servo_parameters_t));
    }
}
