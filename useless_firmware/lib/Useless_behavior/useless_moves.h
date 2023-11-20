/******************************************************************************
 * @file uselsess_moves
 * @brief Store all the useless movement we may use on the robot
 * @author Nicolas Rabault
 * @version 0.0.0
 ******************************************************************************/
#ifndef USELESS_MOVES_H
#define USELESS_MOVES_H
#include "stdint.h"
#include "useless_data.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

typedef struct
{
    // In this struct we save all the informations we need to properly play an animation
    uint32_t priority;     // The highest the priority is compared to other, the more chances the animation have to be executed
    uint32_t frame_number; // The total number of frame in the animation
    const frame_t *frames; // The array of frame
} useless_move_t;

/*******************************************************************************
 * Animation bank
 ******************************************************************************/
const useless_move_t useless_moves[] = {
    // Here we store all the animations we may use (the higher the priority is, the more chances the animation have to be executed)
    // Each line have:
    // {priority, frame_number, frame_t*}
    {7, sizeof(basic) / sizeof(frame_t), basic},
    {5, sizeof(basic_slow) / sizeof(frame_t), basic_slow},
    {5, sizeof(wait_and_fast) / sizeof(frame_t), wait_and_fast},
    {4, sizeof(fuck_and_fast) / sizeof(frame_t), fuck_and_fast},
    {4, sizeof(slow_then_quick_fuck) / sizeof(frame_t), slow_then_quick_fuck},
    {4, sizeof(look_switch_look) / sizeof(frame_t), look_switch_look},
    {4, sizeof(look_switch_fuck) / sizeof(frame_t), look_switch_fuck},
};

const useless_move_t useless_range_moves[] = {
    // Here we store all the range animations we may use (the higher the priority is, the more chances the animation have to be executed)
    // Each line have:
    // {priority, frame_number, frame_t*}
    {1, sizeof(simple_look) / sizeof(frame_t), simple_look},
    {15, sizeof(no_move) / sizeof(frame_t), no_move},
};
#endif /* USELESS_MOVES_H */
