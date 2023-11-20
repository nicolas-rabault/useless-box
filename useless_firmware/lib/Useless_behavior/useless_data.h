/******************************************************************************
 * @file uselsess_data
 * @brief Store all the useless data we may use on the robot
 * @author Nicolas Rabault
 * @version 0.0.0
 ******************************************************************************/
#ifndef USELESS_DATA_H
#define USELESS_DATA_H
#include "stdint.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
typedef enum
{
    STATE_RIGHT,
    STATE_WRONG,
    STATE_UNKNOWN,
    STATE_LED
} expected_state_t;

typedef struct
{
    // All those values have to be between 0 and 100 (integer) representing the percentage of movement amplitude of the motor
    // Remeber that those frames are played at 50Hz
    uint8_t ratios[3]; // { hatch, finger, bonus_hatch}
    uint8_t expected_state;
} frame_t;

/*******************************************************************************
 * Button Data
 ******************************************************************************/
const frame_t basic[] = {
    // { hatch, finger, bonus_hatch, expected_state}
    {{0, 0, 0}, STATE_WRONG},
    {{4, 4, 0}, STATE_WRONG},
    {{8, 8, 0}, STATE_WRONG},
    {{12, 12, 0}, STATE_WRONG},
    {{16, 16, 0}, STATE_WRONG},
    {{20, 20, 0}, STATE_WRONG},
    {{24, 24, 0}, STATE_WRONG},
    {{28, 28, 0}, STATE_WRONG},
    {{32, 32, 0}, STATE_WRONG},
    {{36, 36, 0}, STATE_WRONG},
    {{40, 40, 0}, STATE_WRONG},
    {{44, 44, 0}, STATE_WRONG},
    {{48, 48, 0}, STATE_WRONG},
    {{52, 52, 0}, STATE_WRONG},
    {{56, 56, 0}, STATE_WRONG},
    {{60, 60, 0}, STATE_WRONG},
    {{64, 64, 0}, STATE_WRONG},
    {{68, 68, 0}, STATE_WRONG},
    {{72, 72, 0}, STATE_WRONG},
    {{76, 76, 0}, STATE_WRONG},
    {{80, 80, 0}, STATE_WRONG},
    {{84, 84, 0}, STATE_WRONG},
    {{88, 88, 0}, STATE_WRONG},
    {{92, 92, 0}, STATE_UNKNOWN},
    {{96, 96, 0}, STATE_UNKNOWN},
    {{100, 100, 0}, STATE_UNKNOWN},
    {{100, 100, 0}, STATE_UNKNOWN},
    {{96, 96, 0}, STATE_UNKNOWN},
    {{92, 92, 0}, STATE_UNKNOWN},
    {{88, 88, 0}, STATE_RIGHT},
    {{84, 84, 0}, STATE_RIGHT},
    {{80, 80, 0}, STATE_RIGHT},
    {{76, 76, 0}, STATE_RIGHT},
    {{72, 72, 0}, STATE_RIGHT},
    {{68, 68, 0}, STATE_RIGHT},
    {{64, 64, 0}, STATE_RIGHT},
    {{60, 60, 0}, STATE_RIGHT},
    {{56, 56, 0}, STATE_RIGHT},
    {{52, 52, 0}, STATE_RIGHT},
    {{48, 48, 0}, STATE_RIGHT},
    {{44, 44, 0}, STATE_RIGHT},
    {{40, 40, 0}, STATE_RIGHT},
    {{36, 36, 0}, STATE_RIGHT},
    {{32, 32, 0}, STATE_RIGHT},
    {{28, 28, 0}, STATE_RIGHT},
    {{24, 24, 0}, STATE_RIGHT},
    {{20, 20, 0}, STATE_RIGHT},
    {{16, 16, 0}, STATE_RIGHT},
    {{12, 12, 0}, STATE_RIGHT},
    {{8, 8, 0}, STATE_RIGHT},
    {{4, 4, 0}, STATE_RIGHT},
    {{0, 0, 0}, STATE_RIGHT},
};
const frame_t basic_slow[] = {
    // { hatch, finger, bonus_hatch, expected_state}
    {{0, 0, 0}, STATE_WRONG},
    {{1, 0, 0}, STATE_WRONG},
    {{2, 0, 0}, STATE_WRONG},
    {{3, 0, 0}, STATE_WRONG},
    {{4, 0, 0}, STATE_WRONG},
    {{5, 0, 0}, STATE_WRONG},
    {{6, 0, 0}, STATE_WRONG},
    {{7, 0, 0}, STATE_WRONG},
    {{8, 0, 0}, STATE_WRONG},
    {{9, 0, 0}, STATE_WRONG},
    {{10, 0, 0}, STATE_WRONG},
    {{11, 0, 0}, STATE_WRONG},
    {{12, 0, 0}, STATE_WRONG},
    {{13, 0, 0}, STATE_WRONG},
    {{14, 0, 0}, STATE_WRONG},
    {{15, 0, 0}, STATE_WRONG},
    {{16, 0, 0}, STATE_WRONG},
    {{17, 0, 0}, STATE_WRONG},
    {{18, 0, 0}, STATE_WRONG},
    {{19, 0, 0}, STATE_WRONG},
    {{20, 0, 0}, STATE_WRONG},
    {{21, 0, 0}, STATE_WRONG},
    {{22, 0, 0}, STATE_WRONG},
    {{23, 0, 0}, STATE_WRONG},
    {{24, 0, 0}, STATE_WRONG},
    {{25, 0, 0}, STATE_WRONG},
    {{26, 0, 0}, STATE_WRONG},
    {{27, 0, 0}, STATE_WRONG},
    {{28, 0, 0}, STATE_WRONG},
    {{29, 0, 0}, STATE_WRONG},
    {{30, 0, 0}, STATE_WRONG},
    {{31, 0, 0}, STATE_WRONG},
    {{32, 0, 0}, STATE_WRONG},
    {{33, 0, 0}, STATE_WRONG},
    {{34, 0, 0}, STATE_WRONG},
    {{35, 0, 0}, STATE_WRONG},
    {{36, 0, 0}, STATE_WRONG},
    {{37, 0, 0}, STATE_WRONG},
    {{38, 0, 0}, STATE_WRONG},
    {{39, 0, 0}, STATE_WRONG},
    {{40, 0, 0}, STATE_WRONG},
    {{41, 0, 0}, STATE_WRONG},
    {{42, 0, 0}, STATE_WRONG},
    {{43, 0, 0}, STATE_WRONG},
    {{44, 0, 0}, STATE_WRONG},
    {{45, 0, 0}, STATE_WRONG},
    {{46, 0, 0}, STATE_WRONG},
    {{47, 0, 0}, STATE_WRONG},
    {{48, 0, 0}, STATE_WRONG},
    {{49, 0, 0}, STATE_WRONG},
    {{50, 0, 0}, STATE_WRONG},
    {{51, 0, 0}, STATE_WRONG},
    {{52, 0, 0}, STATE_WRONG},
    {{53, 0, 0}, STATE_WRONG},
    {{54, 0, 0}, STATE_WRONG},
    {{55, 0, 0}, STATE_WRONG},
    {{56, 0, 0}, STATE_WRONG},
    {{57, 0, 0}, STATE_WRONG},
    {{58, 0, 0}, STATE_WRONG},
    {{59, 0, 0}, STATE_WRONG},
    {{60, 0, 0}, STATE_WRONG},
    {{61, 0, 0}, STATE_WRONG},
    {{62, 0, 0}, STATE_WRONG},
    {{63, 0, 0}, STATE_WRONG},
    {{64, 0, 0}, STATE_WRONG},
    {{65, 0, 0}, STATE_WRONG},
    {{66, 0, 0}, STATE_WRONG},
    {{67, 0, 0}, STATE_WRONG},
    {{68, 0, 0}, STATE_WRONG},
    {{69, 0, 0}, STATE_WRONG},
    {{70, 0, 0}, STATE_WRONG},
    {{71, 0, 0}, STATE_WRONG},
    {{72, 0, 0}, STATE_WRONG},
    {{73, 0, 0}, STATE_WRONG},
    {{74, 0, 0}, STATE_WRONG},
    {{75, 0, 0}, STATE_WRONG},
    {{76, 0, 0}, STATE_WRONG},
    {{77, 0, 0}, STATE_WRONG},
    {{78, 0, 0}, STATE_WRONG},
    {{79, 0, 0}, STATE_WRONG},
    {{80, 0, 0}, STATE_WRONG},
    {{81, 0, 0}, STATE_WRONG},
    {{82, 0, 0}, STATE_WRONG},
    {{83, 0, 0}, STATE_WRONG},
    {{84, 0, 0}, STATE_WRONG},
    {{85, 0, 0}, STATE_WRONG},
    {{86, 0, 0}, STATE_WRONG},
    {{87, 0, 0}, STATE_WRONG},
    {{88, 0, 0}, STATE_WRONG},
    {{89, 0, 0}, STATE_WRONG},
    {{90, 0, 0}, STATE_WRONG},
    {{91, 0, 0}, STATE_WRONG},
    {{92, 0, 0}, STATE_WRONG},
    {{93, 0, 0}, STATE_WRONG},
    {{94, 0, 0}, STATE_WRONG},
    {{95, 0, 0}, STATE_WRONG},
    {{96, 0, 0}, STATE_WRONG},
    {{97, 0, 0}, STATE_WRONG},
    {{98, 0, 0}, STATE_WRONG},
    {{99, 0, 0}, STATE_WRONG},
    {{100, 0, 0}, STATE_WRONG},
    {{100, 1, 0}, STATE_WRONG},
    {{100, 2, 0}, STATE_WRONG},
    {{100, 3, 0}, STATE_WRONG},
    {{100, 4, 0}, STATE_WRONG},
    {{100, 5, 0}, STATE_WRONG},
    {{100, 6, 0}, STATE_WRONG},
    {{100, 7, 0}, STATE_WRONG},
    {{100, 8, 0}, STATE_WRONG},
    {{100, 9, 0}, STATE_WRONG},
    {{100, 10, 0}, STATE_WRONG},
    {{100, 11, 0}, STATE_WRONG},
    {{100, 12, 0}, STATE_WRONG},
    {{100, 13, 0}, STATE_WRONG},
    {{100, 14, 0}, STATE_WRONG},
    {{100, 15, 0}, STATE_WRONG},
    {{100, 16, 0}, STATE_WRONG},
    {{100, 17, 0}, STATE_WRONG},
    {{100, 18, 0}, STATE_WRONG},
    {{100, 19, 0}, STATE_WRONG},
    {{100, 20, 0}, STATE_WRONG},
    {{100, 21, 0}, STATE_WRONG},
    {{100, 22, 0}, STATE_WRONG},
    {{100, 23, 0}, STATE_WRONG},
    {{100, 24, 0}, STATE_WRONG},
    {{100, 25, 0}, STATE_WRONG},
    {{100, 26, 0}, STATE_WRONG},
    {{100, 27, 0}, STATE_WRONG},
    {{100, 28, 0}, STATE_WRONG},
    {{100, 29, 0}, STATE_WRONG},
    {{100, 30, 0}, STATE_WRONG},
    {{100, 31, 0}, STATE_WRONG},
    {{100, 32, 0}, STATE_WRONG},
    {{100, 33, 0}, STATE_WRONG},
    {{100, 34, 0}, STATE_WRONG},
    {{100, 35, 0}, STATE_WRONG},
    {{100, 36, 0}, STATE_WRONG},
    {{100, 37, 0}, STATE_WRONG},
    {{100, 38, 0}, STATE_WRONG},
    {{100, 39, 0}, STATE_WRONG},
    {{100, 40, 0}, STATE_WRONG},
    {{100, 41, 0}, STATE_WRONG},
    {{100, 42, 0}, STATE_WRONG},
    {{100, 43, 0}, STATE_WRONG},
    {{100, 44, 0}, STATE_WRONG},
    {{100, 45, 0}, STATE_WRONG},
    {{100, 46, 0}, STATE_WRONG},
    {{100, 47, 0}, STATE_WRONG},
    {{100, 48, 0}, STATE_WRONG},
    {{100, 49, 0}, STATE_WRONG},
    {{100, 50, 0}, STATE_WRONG},
    {{100, 51, 0}, STATE_WRONG},
    {{100, 52, 0}, STATE_WRONG},
    {{100, 53, 0}, STATE_WRONG},
    {{100, 54, 0}, STATE_WRONG},
    {{100, 55, 0}, STATE_WRONG},
    {{100, 56, 0}, STATE_WRONG},
    {{100, 57, 0}, STATE_WRONG},
    {{100, 58, 0}, STATE_WRONG},
    {{100, 59, 0}, STATE_WRONG},
    {{100, 60, 0}, STATE_WRONG},
    {{100, 61, 0}, STATE_WRONG},
    {{100, 62, 0}, STATE_WRONG},
    {{100, 63, 0}, STATE_WRONG},
    {{100, 64, 0}, STATE_WRONG},
    {{100, 65, 0}, STATE_WRONG},
    {{100, 66, 0}, STATE_WRONG},
    {{100, 67, 0}, STATE_WRONG},
    {{100, 68, 0}, STATE_WRONG},
    {{100, 69, 0}, STATE_WRONG},
    {{100, 70, 0}, STATE_WRONG},
    {{100, 71, 0}, STATE_WRONG},
    {{100, 72, 0}, STATE_WRONG},
    {{100, 73, 0}, STATE_WRONG},
    {{100, 74, 0}, STATE_WRONG},
    {{100, 75, 0}, STATE_WRONG},
    {{100, 100, 0}, STATE_UNKNOWN},
    {{100, 100, 0}, STATE_UNKNOWN},
    {{100, 100, 0}, STATE_UNKNOWN},
    {{100, 100, 0}, STATE_UNKNOWN},
    {{100, 100, 0}, STATE_UNKNOWN},
    {{100, 100, 0}, STATE_UNKNOWN},
    {{100, 100, 0}, STATE_UNKNOWN},
    {{100, 100, 0}, STATE_UNKNOWN},
    {{100, 100, 0}, STATE_UNKNOWN},
    {{100, 100, 0}, STATE_UNKNOWN},
    {{100, 100, 0}, STATE_UNKNOWN},
    {{100, 100, 0}, STATE_UNKNOWN},
    {{100, 100, 0}, STATE_UNKNOWN},
    {{100, 100, 0}, STATE_UNKNOWN},
    {{100, 100, 0}, STATE_UNKNOWN},
    {{100, 100, 0}, STATE_UNKNOWN},
    {{100, 100, 0}, STATE_UNKNOWN},
    {{100, 100, 0}, STATE_UNKNOWN},
    {{100, 100, 0}, STATE_UNKNOWN},
    {{100, 100, 0}, STATE_UNKNOWN},
    {{100, 100, 0}, STATE_UNKNOWN},
    {{100, 100, 0}, STATE_UNKNOWN},
    {{100, 100, 0}, STATE_UNKNOWN},
    {{100, 100, 0}, STATE_UNKNOWN},
    {{100, 100, 0}, STATE_UNKNOWN},
    {{100, 99, 0}, STATE_UNKNOWN},
    {{100, 98, 0}, STATE_UNKNOWN},
    {{100, 97, 0}, STATE_RIGHT},
    {{100, 96, 0}, STATE_RIGHT},
    {{100, 95, 0}, STATE_RIGHT},
    {{100, 94, 0}, STATE_RIGHT},
    {{100, 93, 0}, STATE_RIGHT},
    {{100, 92, 0}, STATE_RIGHT},
    {{100, 91, 0}, STATE_RIGHT},
    {{100, 90, 0}, STATE_RIGHT},
    {{100, 89, 0}, STATE_RIGHT},
    {{100, 88, 0}, STATE_RIGHT},
    {{100, 87, 0}, STATE_RIGHT},
    {{100, 86, 0}, STATE_RIGHT},
    {{100, 85, 0}, STATE_RIGHT},
    {{100, 84, 0}, STATE_RIGHT},
    {{100, 83, 0}, STATE_RIGHT},
    {{100, 82, 0}, STATE_RIGHT},
    {{100, 81, 0}, STATE_RIGHT},
    {{100, 80, 0}, STATE_RIGHT},
    {{100, 79, 0}, STATE_RIGHT},
    {{100, 78, 0}, STATE_RIGHT},
    {{100, 77, 0}, STATE_RIGHT},
    {{100, 76, 0}, STATE_RIGHT},
    {{100, 75, 0}, STATE_RIGHT},
    {{100, 74, 0}, STATE_RIGHT},
    {{100, 73, 0}, STATE_RIGHT},
    {{100, 72, 0}, STATE_RIGHT},
    {{100, 71, 0}, STATE_RIGHT},
    {{100, 70, 0}, STATE_RIGHT},
    {{100, 69, 0}, STATE_RIGHT},
    {{100, 68, 0}, STATE_RIGHT},
    {{100, 67, 0}, STATE_RIGHT},
    {{100, 66, 0}, STATE_RIGHT},
    {{100, 65, 0}, STATE_RIGHT},
    {{100, 64, 0}, STATE_RIGHT},
    {{100, 63, 0}, STATE_RIGHT},
    {{100, 62, 0}, STATE_RIGHT},
    {{100, 61, 0}, STATE_RIGHT},
    {{100, 60, 0}, STATE_RIGHT},
    {{100, 59, 0}, STATE_RIGHT},
    {{100, 58, 0}, STATE_RIGHT},
    {{100, 57, 0}, STATE_RIGHT},
    {{100, 56, 0}, STATE_RIGHT},
    {{100, 55, 0}, STATE_RIGHT},
    {{100, 54, 0}, STATE_RIGHT},
    {{100, 53, 0}, STATE_RIGHT},
    {{100, 52, 0}, STATE_RIGHT},
    {{100, 51, 0}, STATE_RIGHT},
    {{100, 50, 0}, STATE_RIGHT},
    {{100, 49, 0}, STATE_RIGHT},
    {{100, 48, 0}, STATE_RIGHT},
    {{100, 47, 0}, STATE_RIGHT},
    {{100, 46, 0}, STATE_RIGHT},
    {{100, 45, 0}, STATE_RIGHT},
    {{100, 44, 0}, STATE_RIGHT},
    {{100, 43, 0}, STATE_RIGHT},
    {{100, 42, 0}, STATE_RIGHT},
    {{100, 41, 0}, STATE_RIGHT},
    {{100, 40, 0}, STATE_RIGHT},
    {{100, 39, 0}, STATE_RIGHT},
    {{100, 38, 0}, STATE_RIGHT},
    {{100, 37, 0}, STATE_RIGHT},
    {{100, 36, 0}, STATE_RIGHT},
    {{100, 35, 0}, STATE_RIGHT},
    {{100, 34, 0}, STATE_RIGHT},
    {{100, 33, 0}, STATE_RIGHT},
    {{100, 32, 0}, STATE_RIGHT},
    {{100, 31, 0}, STATE_RIGHT},
    {{100, 30, 0}, STATE_RIGHT},
    {{100, 29, 0}, STATE_RIGHT},
    {{100, 28, 0}, STATE_RIGHT},
    {{100, 27, 0}, STATE_RIGHT},
    {{100, 26, 0}, STATE_RIGHT},
    {{100, 25, 0}, STATE_RIGHT},
    {{96, 24, 0}, STATE_RIGHT},
    {{92, 23, 0}, STATE_RIGHT},
    {{88, 22, 0}, STATE_RIGHT},
    {{84, 21, 0}, STATE_RIGHT},
    {{80, 20, 0}, STATE_RIGHT},
    {{76, 19, 0}, STATE_RIGHT},
    {{72, 18, 0}, STATE_RIGHT},
    {{68, 17, 0}, STATE_RIGHT},
    {{64, 16, 0}, STATE_RIGHT},
    {{60, 15, 0}, STATE_RIGHT},
    {{56, 14, 0}, STATE_RIGHT},
    {{52, 13, 0}, STATE_RIGHT},
    {{48, 12, 0}, STATE_RIGHT},
    {{44, 11, 0}, STATE_RIGHT},
    {{40, 10, 0}, STATE_RIGHT},
    {{36, 9, 0}, STATE_RIGHT},
    {{32, 8, 0}, STATE_RIGHT},
    {{28, 7, 0}, STATE_RIGHT},
    {{24, 6, 0}, STATE_RIGHT},
    {{20, 5, 0}, STATE_RIGHT},
    {{16, 4, 0}, STATE_RIGHT},
    {{12, 3, 0}, STATE_RIGHT},
    {{8, 2, 0}, STATE_RIGHT},
    {{4, 1, 0}, STATE_RIGHT},
    {{0, 0, 0}, STATE_RIGHT}};
const frame_t wait_and_fast[] = {
    // { hatch, finger, bonus_hatch, expected_state}
    {{0, 0, 0}, STATE_WRONG},
    {{20, 0, 0}, STATE_WRONG},
    {{20, 0, 0}, STATE_WRONG},
    {{20, 0, 0}, STATE_WRONG},
    {{20, 0, 0}, STATE_WRONG},
    {{20, 0, 0}, STATE_WRONG},
    {{20, 0, 0}, STATE_WRONG},
    {{20, 0, 0}, STATE_WRONG},
    {{20, 0, 0}, STATE_WRONG},
    {{20, 0, 0}, STATE_WRONG},
    {{20, 0, 0}, STATE_WRONG},
    {{20, 0, 0}, STATE_WRONG},
    {{20, 0, 0}, STATE_WRONG},
    {{20, 0, 0}, STATE_WRONG},
    {{20, 0, 0}, STATE_WRONG},
    {{20, 0, 0}, STATE_WRONG},
    {{20, 0, 0}, STATE_WRONG},
    {{20, 0, 0}, STATE_WRONG},
    {{20, 0, 0}, STATE_WRONG},
    {{20, 0, 0}, STATE_WRONG},
    {{20, 0, 0}, STATE_WRONG},
    {{20, 0, 0}, STATE_WRONG},
    {{20, 0, 0}, STATE_WRONG},
    {{20, 0, 0}, STATE_WRONG},
    {{20, 0, 0}, STATE_WRONG},
    {{20, 0, 0}, STATE_WRONG},
    {{20, 0, 0}, STATE_WRONG},
    {{18, 0, 0}, STATE_WRONG},
    {{16, 0, 0}, STATE_WRONG},
    {{14, 0, 0}, STATE_WRONG},
    {{12, 0, 0}, STATE_WRONG},
    {{10, 0, 0}, STATE_WRONG},
    {{8, 0, 0}, STATE_WRONG},
    {{6, 0, 0}, STATE_WRONG},
    {{4, 0, 0}, STATE_WRONG},
    {{2, 0, 0}, STATE_WRONG},
    {{0, 0, 0}, STATE_WRONG},
    {{0, 0, 0}, STATE_WRONG},
    {{0, 0, 0}, STATE_WRONG},
    {{0, 0, 0}, STATE_WRONG},
    {{0, 0, 0}, STATE_WRONG},
    {{0, 0, 0}, STATE_WRONG},
    {{0, 0, 0}, STATE_WRONG},
    {{0, 0, 0}, STATE_WRONG},
    {{0, 0, 0}, STATE_WRONG},
    {{0, 0, 0}, STATE_WRONG},
    {{0, 0, 0}, STATE_WRONG},
    {{0, 0, 0}, STATE_WRONG},
    {{0, 0, 0}, STATE_WRONG},
    {{0, 0, 0}, STATE_WRONG},
    {{0, 0, 0}, STATE_WRONG},
    {{0, 0, 0}, STATE_WRONG},
    {{0, 0, 0}, STATE_WRONG},
    {{0, 0, 0}, STATE_WRONG},
    {{0, 0, 0}, STATE_WRONG},
    {{0, 0, 0}, STATE_WRONG},
    {{0, 0, 0}, STATE_WRONG},
    {{8, 8, 0}, STATE_WRONG},
    {{16, 16, 0}, STATE_WRONG},
    {{24, 24, 0}, STATE_WRONG},
    {{32, 32, 0}, STATE_WRONG},
    {{40, 40, 0}, STATE_WRONG},
    {{48, 48, 0}, STATE_WRONG},
    {{56, 56, 0}, STATE_WRONG},
    {{64, 64, 0}, STATE_WRONG},
    {{72, 72, 0}, STATE_WRONG},
    {{80, 80, 0}, STATE_WRONG},
    {{88, 88, 0}, STATE_UNKNOWN},
    {{96, 96, 0}, STATE_UNKNOWN},
    {{100, 100, 0}, STATE_UNKNOWN},
    {{100, 100, 0}, STATE_UNKNOWN},
    {{96, 96, 0}, STATE_UNKNOWN},
    {{88, 88, 0}, STATE_UNKNOWN},
    {{80, 80, 0}, STATE_RIGHT},
    {{72, 72, 0}, STATE_RIGHT},
    {{64, 64, 0}, STATE_RIGHT},
    {{56, 56, 0}, STATE_RIGHT},
    {{48, 48, 0}, STATE_RIGHT},
    {{40, 40, 0}, STATE_RIGHT},
    {{32, 32, 0}, STATE_RIGHT},
    {{24, 24, 0}, STATE_RIGHT},
    {{16, 16, 0}, STATE_RIGHT},
    {{8, 8, 0}, STATE_RIGHT},
    {{0, 0, 0}, STATE_RIGHT}};
const frame_t fuck_and_fast[] = {
    // { hatch, finger, bonus_hatch, expected_state}
    {{0, 0, 0}, STATE_WRONG},
    {{0, 0, 8}, STATE_WRONG},
    {{0, 0, 16}, STATE_WRONG},
    {{0, 0, 24}, STATE_WRONG},
    {{0, 0, 32}, STATE_WRONG},
    {{0, 0, 48}, STATE_WRONG},
    {{0, 0, 52}, STATE_WRONG},
    {{0, 0, 56}, STATE_WRONG},
    {{0, 0, 60}, STATE_WRONG},
    {{0, 0, 100}, STATE_WRONG},
    {{0, 0, 100}, STATE_WRONG},
    {{0, 0, 100}, STATE_WRONG},
    {{0, 0, 100}, STATE_WRONG},
    {{0, 0, 100}, STATE_WRONG},
    {{0, 0, 100}, STATE_WRONG},
    {{0, 0, 100}, STATE_WRONG},
    {{0, 0, 100}, STATE_WRONG},
    {{0, 0, 100}, STATE_WRONG},
    {{0, 0, 100}, STATE_WRONG},
    {{0, 0, 100}, STATE_WRONG},
    {{0, 0, 100}, STATE_WRONG},
    {{0, 0, 100}, STATE_WRONG},
    {{0, 0, 100}, STATE_WRONG},
    {{0, 0, 100}, STATE_WRONG},
    {{0, 0, 100}, STATE_WRONG},
    {{0, 0, 100}, STATE_WRONG},
    {{0, 0, 100}, STATE_WRONG},
    {{0, 0, 100}, STATE_WRONG},
    {{0, 0, 100}, STATE_WRONG},
    {{0, 0, 100}, STATE_WRONG},
    {{0, 0, 100}, STATE_WRONG},
    {{0, 0, 100}, STATE_WRONG},
    {{0, 0, 100}, STATE_WRONG},
    {{0, 0, 100}, STATE_WRONG},
    {{0, 0, 100}, STATE_WRONG},
    {{0, 0, 100}, STATE_WRONG},
    {{0, 0, 100}, STATE_WRONG},
    {{0, 0, 100}, STATE_WRONG},
    {{0, 0, 100}, STATE_WRONG},
    {{0, 0, 100}, STATE_WRONG},
    {{0, 0, 100}, STATE_WRONG},
    {{0, 0, 100}, STATE_WRONG},
    {{0, 0, 100}, STATE_WRONG},
    {{0, 0, 100}, STATE_WRONG},
    {{0, 0, 100}, STATE_WRONG},
    {{0, 0, 100}, STATE_WRONG},
    {{0, 0, 100}, STATE_WRONG},
    {{0, 0, 100}, STATE_WRONG},
    {{0, 0, 100}, STATE_WRONG},
    {{0, 0, 100}, STATE_WRONG},
    {{0, 0, 100}, STATE_WRONG},
    {{0, 0, 100}, STATE_WRONG},
    {{0, 0, 100}, STATE_WRONG},
    {{0, 0, 100}, STATE_WRONG},
    {{0, 0, 100}, STATE_WRONG},
    {{0, 0, 100}, STATE_WRONG},
    {{8, 8, 0}, STATE_WRONG},
    {{16, 16, 0}, STATE_WRONG},
    {{24, 24, 0}, STATE_WRONG},
    {{32, 32, 0}, STATE_WRONG},
    {{40, 40, 0}, STATE_WRONG},
    {{48, 48, 0}, STATE_WRONG},
    {{56, 56, 0}, STATE_WRONG},
    {{64, 64, 0}, STATE_WRONG},
    {{72, 72, 0}, STATE_WRONG},
    {{80, 80, 0}, STATE_WRONG},
    {{88, 88, 0}, STATE_UNKNOWN},
    {{96, 96, 0}, STATE_UNKNOWN},
    {{100, 100, 0}, STATE_UNKNOWN},
    {{100, 100, 0}, STATE_UNKNOWN},
    {{96, 96, 0}, STATE_UNKNOWN},
    {{88, 88, 0}, STATE_UNKNOWN},
    {{80, 80, 0}, STATE_RIGHT},
    {{72, 72, 0}, STATE_RIGHT},
    {{64, 64, 0}, STATE_RIGHT},
    {{56, 56, 0}, STATE_RIGHT},
    {{48, 48, 0}, STATE_RIGHT},
    {{40, 40, 0}, STATE_RIGHT},
    {{32, 32, 0}, STATE_RIGHT},
    {{24, 24, 0}, STATE_RIGHT},
    {{16, 16, 0}, STATE_RIGHT},
    {{8, 8, 0}, STATE_RIGHT},
    {{0, 0, 0}, STATE_RIGHT}};
const frame_t slow_then_quick_fuck[] = {
    // { hatch, finger, bonus_hatch, expected_state}
    {{0, 0, 0}, STATE_WRONG},
    {{1, 0, 0}, STATE_WRONG},
    {{2, 0, 0}, STATE_WRONG},
    {{3, 0, 0}, STATE_WRONG},
    {{4, 0, 0}, STATE_WRONG},
    {{5, 0, 0}, STATE_WRONG},
    {{6, 0, 0}, STATE_WRONG},
    {{7, 0, 0}, STATE_WRONG},
    {{8, 0, 0}, STATE_WRONG},
    {{9, 0, 0}, STATE_WRONG},
    {{10, 0, 0}, STATE_WRONG},
    {{11, 0, 0}, STATE_WRONG},
    {{12, 0, 0}, STATE_WRONG},
    {{13, 0, 0}, STATE_WRONG},
    {{14, 0, 0}, STATE_WRONG},
    {{15, 0, 0}, STATE_WRONG},
    {{16, 0, 0}, STATE_WRONG},
    {{17, 0, 0}, STATE_WRONG},
    {{18, 0, 0}, STATE_WRONG},
    {{19, 0, 0}, STATE_WRONG},
    {{20, 0, 0}, STATE_WRONG},
    {{21, 0, 0}, STATE_WRONG},
    {{22, 0, 0}, STATE_WRONG},
    {{23, 0, 0}, STATE_WRONG},
    {{24, 0, 0}, STATE_WRONG},
    {{25, 0, 0}, STATE_WRONG},
    {{26, 0, 0}, STATE_WRONG},
    {{27, 0, 0}, STATE_WRONG},
    {{28, 0, 0}, STATE_WRONG},
    {{29, 0, 0}, STATE_WRONG},
    {{30, 0, 0}, STATE_WRONG},
    {{31, 0, 0}, STATE_WRONG},
    {{32, 0, 0}, STATE_WRONG},
    {{33, 0, 0}, STATE_WRONG},
    {{34, 0, 0}, STATE_WRONG},
    {{35, 0, 0}, STATE_WRONG},
    {{36, 0, 0}, STATE_WRONG},
    {{37, 0, 0}, STATE_WRONG},
    {{38, 0, 0}, STATE_WRONG},
    {{39, 0, 0}, STATE_WRONG},
    {{40, 0, 0}, STATE_WRONG},
    {{41, 0, 0}, STATE_WRONG},
    {{42, 0, 0}, STATE_WRONG},
    {{43, 0, 0}, STATE_WRONG},
    {{44, 0, 0}, STATE_WRONG},
    {{45, 0, 0}, STATE_WRONG},
    {{46, 0, 0}, STATE_WRONG},
    {{47, 0, 0}, STATE_WRONG},
    {{48, 0, 0}, STATE_WRONG},
    {{49, 0, 0}, STATE_WRONG},
    {{50, 0, 0}, STATE_WRONG},
    {{51, 0, 0}, STATE_WRONG},
    {{52, 0, 0}, STATE_WRONG},
    {{53, 0, 0}, STATE_WRONG},
    {{54, 0, 0}, STATE_WRONG},
    {{55, 0, 0}, STATE_WRONG},
    {{56, 0, 0}, STATE_WRONG},
    {{57, 0, 0}, STATE_WRONG},
    {{58, 0, 0}, STATE_WRONG},
    {{59, 0, 0}, STATE_WRONG},
    {{60, 0, 0}, STATE_WRONG},
    {{61, 0, 0}, STATE_WRONG},
    {{62, 0, 0}, STATE_WRONG},
    {{63, 0, 0}, STATE_WRONG},
    {{64, 0, 0}, STATE_WRONG},
    {{65, 0, 0}, STATE_WRONG},
    {{66, 0, 0}, STATE_WRONG},
    {{67, 0, 0}, STATE_WRONG},
    {{68, 0, 0}, STATE_WRONG},
    {{69, 0, 0}, STATE_WRONG},
    {{70, 0, 0}, STATE_WRONG},
    {{71, 0, 0}, STATE_WRONG},
    {{72, 0, 0}, STATE_WRONG},
    {{73, 0, 0}, STATE_WRONG},
    {{74, 0, 0}, STATE_WRONG},
    {{75, 0, 0}, STATE_WRONG},
    {{76, 0, 0}, STATE_WRONG},
    {{77, 0, 0}, STATE_WRONG},
    {{78, 0, 0}, STATE_WRONG},
    {{79, 0, 0}, STATE_WRONG},
    {{80, 0, 0}, STATE_WRONG},
    {{81, 0, 0}, STATE_WRONG},
    {{82, 0, 0}, STATE_WRONG},
    {{83, 0, 0}, STATE_WRONG},
    {{84, 0, 0}, STATE_WRONG},
    {{85, 0, 0}, STATE_WRONG},
    {{86, 0, 0}, STATE_WRONG},
    {{87, 0, 0}, STATE_WRONG},
    {{88, 0, 0}, STATE_WRONG},
    {{89, 0, 0}, STATE_WRONG},
    {{90, 0, 0}, STATE_WRONG},
    {{91, 0, 0}, STATE_WRONG},
    {{92, 0, 0}, STATE_WRONG},
    {{93, 0, 0}, STATE_WRONG},
    {{94, 0, 0}, STATE_WRONG},
    {{95, 0, 0}, STATE_WRONG},
    {{96, 0, 0}, STATE_WRONG},
    {{97, 0, 0}, STATE_WRONG},
    {{98, 0, 0}, STATE_WRONG},
    {{99, 0, 0}, STATE_WRONG},
    {{100, 0, 0}, STATE_WRONG},
    {{100, 1, 0}, STATE_WRONG},
    {{100, 2, 0}, STATE_WRONG},
    {{100, 3, 0}, STATE_WRONG},
    {{100, 4, 0}, STATE_WRONG},
    {{100, 5, 0}, STATE_WRONG},
    {{100, 6, 0}, STATE_WRONG},
    {{100, 7, 0}, STATE_WRONG},
    {{100, 8, 0}, STATE_WRONG},
    {{100, 9, 0}, STATE_WRONG},
    {{100, 10, 0}, STATE_WRONG},
    {{100, 11, 0}, STATE_WRONG},
    {{100, 12, 0}, STATE_WRONG},
    {{100, 13, 0}, STATE_WRONG},
    {{100, 14, 0}, STATE_WRONG},
    {{100, 15, 0}, STATE_WRONG},
    {{100, 16, 0}, STATE_WRONG},
    {{100, 17, 0}, STATE_WRONG},
    {{100, 18, 0}, STATE_WRONG},
    {{100, 19, 0}, STATE_WRONG},
    {{100, 20, 0}, STATE_WRONG},
    {{100, 21, 0}, STATE_WRONG},
    {{100, 22, 0}, STATE_WRONG},
    {{100, 23, 0}, STATE_WRONG},
    {{100, 24, 0}, STATE_WRONG},
    {{100, 25, 0}, STATE_WRONG},
    {{100, 26, 0}, STATE_WRONG},
    {{100, 27, 0}, STATE_WRONG},
    {{100, 28, 0}, STATE_WRONG},
    {{100, 29, 0}, STATE_WRONG},
    {{100, 30, 0}, STATE_WRONG},
    {{100, 31, 0}, STATE_WRONG},
    {{100, 32, 0}, STATE_WRONG},
    {{100, 33, 0}, STATE_WRONG},
    {{100, 34, 0}, STATE_WRONG},
    {{100, 35, 0}, STATE_WRONG},
    {{100, 36, 0}, STATE_WRONG},
    {{100, 37, 0}, STATE_WRONG},
    {{100, 38, 0}, STATE_WRONG},
    {{100, 39, 0}, STATE_WRONG},
    {{100, 40, 0}, STATE_WRONG},
    {{100, 41, 0}, STATE_WRONG},
    {{100, 42, 0}, STATE_WRONG},
    {{100, 43, 0}, STATE_WRONG},
    {{100, 44, 0}, STATE_WRONG},
    {{100, 45, 0}, STATE_WRONG},
    {{100, 46, 0}, STATE_WRONG},
    {{100, 47, 0}, STATE_WRONG},
    {{100, 48, 0}, STATE_WRONG},
    {{100, 49, 0}, STATE_WRONG},
    {{100, 50, 0}, STATE_WRONG},
    {{100, 51, 0}, STATE_WRONG},
    {{100, 52, 0}, STATE_WRONG},
    {{100, 53, 0}, STATE_WRONG},
    {{100, 54, 0}, STATE_WRONG},
    {{100, 55, 0}, STATE_WRONG},
    {{100, 56, 0}, STATE_WRONG},
    {{100, 57, 0}, STATE_WRONG},
    {{100, 58, 0}, STATE_WRONG},
    {{100, 59, 0}, STATE_WRONG},
    {{100, 60, 0}, STATE_WRONG},
    {{100, 61, 0}, STATE_WRONG},
    {{100, 62, 0}, STATE_WRONG},
    {{100, 63, 0}, STATE_WRONG},
    {{100, 64, 0}, STATE_WRONG},
    {{100, 65, 0}, STATE_WRONG},
    {{100, 66, 0}, STATE_WRONG},
    {{100, 67, 0}, STATE_WRONG},
    {{100, 68, 0}, STATE_WRONG},
    {{100, 69, 0}, STATE_WRONG},
    {{100, 70, 0}, STATE_WRONG},
    {{100, 71, 0}, STATE_WRONG},
    {{100, 72, 0}, STATE_WRONG},
    {{100, 73, 0}, STATE_WRONG},
    {{100, 74, 0}, STATE_WRONG},
    {{100, 75, 0}, STATE_WRONG},
    {{100, 100, 0}, STATE_UNKNOWN},
    {{100, 100, 0}, STATE_UNKNOWN},
    {{100, 100, 0}, STATE_UNKNOWN},
    {{100, 100, 0}, STATE_UNKNOWN},
    {{100, 100, 0}, STATE_UNKNOWN},
    {{100, 100, 0}, STATE_UNKNOWN},
    {{100, 100, 0}, STATE_UNKNOWN},
    {{100, 100, 0}, STATE_UNKNOWN},
    {{100, 100, 0}, STATE_UNKNOWN},
    {{100, 100, 0}, STATE_UNKNOWN},
    {{100, 100, 0}, STATE_UNKNOWN},
    {{100, 100, 0}, STATE_UNKNOWN},
    {{100, 100, 0}, STATE_UNKNOWN},
    {{100, 100, 0}, STATE_UNKNOWN},
    {{100, 100, 0}, STATE_UNKNOWN},
    {{100, 100, 0}, STATE_UNKNOWN},
    {{100, 100, 0}, STATE_UNKNOWN},
    {{100, 100, 0}, STATE_UNKNOWN},
    {{100, 100, 0}, STATE_UNKNOWN},
    {{100, 100, 0}, STATE_UNKNOWN},
    {{100, 100, 0}, STATE_UNKNOWN},
    {{100, 100, 0}, STATE_UNKNOWN},
    {{100, 100, 0}, STATE_UNKNOWN},
    {{100, 100, 0}, STATE_UNKNOWN},
    {{100, 100, 0}, STATE_UNKNOWN},
    {{100, 99, 0}, STATE_UNKNOWN},
    {{100, 98, 0}, STATE_UNKNOWN},
    {{100, 97, 0}, STATE_RIGHT},
    {{100, 96, 0}, STATE_RIGHT},
    {{100, 95, 0}, STATE_RIGHT},
    {{100, 94, 0}, STATE_RIGHT},
    {{100, 93, 0}, STATE_RIGHT},
    {{100, 92, 0}, STATE_RIGHT},
    {{100, 91, 0}, STATE_RIGHT},
    {{100, 90, 0}, STATE_RIGHT},
    {{100, 89, 0}, STATE_RIGHT},
    {{100, 88, 0}, STATE_RIGHT},
    {{100, 87, 0}, STATE_RIGHT},
    {{100, 86, 0}, STATE_RIGHT},
    {{100, 85, 0}, STATE_RIGHT},
    {{100, 84, 0}, STATE_RIGHT},
    {{100, 83, 0}, STATE_RIGHT},
    {{100, 82, 0}, STATE_RIGHT},
    {{100, 81, 0}, STATE_RIGHT},
    {{100, 80, 0}, STATE_RIGHT},
    {{100, 79, 0}, STATE_RIGHT},
    {{100, 78, 0}, STATE_RIGHT},
    {{100, 77, 0}, STATE_RIGHT},
    {{100, 76, 0}, STATE_RIGHT},
    {{100, 75, 0}, STATE_RIGHT},
    {{100, 74, 0}, STATE_RIGHT},
    {{100, 73, 0}, STATE_RIGHT},
    {{100, 72, 0}, STATE_RIGHT},
    {{100, 71, 0}, STATE_RIGHT},
    {{100, 70, 0}, STATE_RIGHT},
    {{100, 69, 0}, STATE_RIGHT},
    {{100, 68, 0}, STATE_RIGHT},
    {{100, 67, 0}, STATE_RIGHT},
    {{100, 66, 0}, STATE_RIGHT},
    {{100, 65, 0}, STATE_RIGHT},
    {{100, 64, 0}, STATE_RIGHT},
    {{100, 63, 0}, STATE_RIGHT},
    {{100, 62, 0}, STATE_RIGHT},
    {{100, 61, 0}, STATE_RIGHT},
    {{100, 60, 0}, STATE_RIGHT},
    {{100, 59, 0}, STATE_RIGHT},
    {{100, 58, 0}, STATE_RIGHT},
    {{100, 57, 0}, STATE_RIGHT},
    {{100, 56, 0}, STATE_RIGHT},
    {{100, 55, 0}, STATE_RIGHT},
    {{100, 54, 0}, STATE_RIGHT},
    {{100, 53, 0}, STATE_RIGHT},
    {{100, 52, 0}, STATE_RIGHT},
    {{100, 51, 0}, STATE_RIGHT},
    {{100, 50, 0}, STATE_RIGHT},
    {{100, 49, 0}, STATE_RIGHT},
    {{100, 48, 0}, STATE_RIGHT},
    {{100, 47, 0}, STATE_RIGHT},
    {{100, 46, 0}, STATE_RIGHT},
    {{100, 45, 0}, STATE_RIGHT},
    {{100, 44, 0}, STATE_RIGHT},
    {{100, 43, 0}, STATE_RIGHT},
    {{100, 42, 0}, STATE_RIGHT},
    {{100, 41, 0}, STATE_RIGHT},
    {{100, 40, 0}, STATE_RIGHT},
    {{100, 39, 0}, STATE_RIGHT},
    {{100, 38, 0}, STATE_RIGHT},
    {{100, 37, 100}, STATE_RIGHT},
    {{100, 36, 100}, STATE_RIGHT},
    {{100, 35, 100}, STATE_RIGHT},
    {{100, 34, 100}, STATE_RIGHT},
    {{100, 33, 100}, STATE_RIGHT},
    {{100, 32, 100}, STATE_RIGHT},
    {{100, 31, 100}, STATE_RIGHT},
    {{100, 30, 100}, STATE_RIGHT},
    {{100, 29, 100}, STATE_RIGHT},
    {{100, 28, 100}, STATE_RIGHT},
    {{100, 27, 100}, STATE_RIGHT},
    {{100, 26, 100}, STATE_RIGHT},
    {{100, 25, 100}, STATE_RIGHT},
    {{96, 24, 100}, STATE_RIGHT},
    {{92, 23, 100}, STATE_RIGHT},
    {{88, 22, 100}, STATE_RIGHT},
    {{84, 21, 100}, STATE_RIGHT},
    {{80, 20, 100}, STATE_RIGHT},
    {{76, 19, 100}, STATE_RIGHT},
    {{72, 18, 100}, STATE_RIGHT},
    {{68, 17, 100}, STATE_RIGHT},
    {{64, 16, 100}, STATE_RIGHT},
    {{60, 15, 100}, STATE_RIGHT},
    {{56, 14, 100}, STATE_RIGHT},
    {{52, 13, 100}, STATE_RIGHT},
    {{48, 12, 100}, STATE_RIGHT},
    {{44, 11, 100}, STATE_RIGHT},
    {{40, 10, 100}, STATE_RIGHT},
    {{36, 9, 100}, STATE_RIGHT},
    {{32, 8, 100}, STATE_RIGHT},
    {{28, 7, 100}, STATE_RIGHT},
    {{24, 6, 100}, STATE_RIGHT},
    {{20, 5, 100}, STATE_RIGHT},
    {{16, 4, 100}, STATE_RIGHT},
    {{12, 3, 100}, STATE_RIGHT},
    {{8, 2, 100}, STATE_RIGHT},
    {{4, 1, 0}, STATE_RIGHT},
    {{0, 0, 0}, STATE_RIGHT}};
const frame_t look_switch_look[] = {
    // { hatch, finger, bonus_hatch, expected_state}
    {{0, 0, 0}, STATE_WRONG},
    {{100, 60, 0}, STATE_WRONG},
    {{100, 60, 0}, STATE_WRONG},
    {{100, 60, 0}, STATE_WRONG},
    {{100, 60, 0}, STATE_WRONG},
    {{100, 60, 0}, STATE_WRONG},
    {{100, 60, 0}, STATE_WRONG},
    {{100, 60, 0}, STATE_WRONG},
    {{100, 60, 0}, STATE_WRONG},
    {{100, 60, 0}, STATE_WRONG},
    {{100, 60, 0}, STATE_WRONG},
    {{100, 60, 0}, STATE_WRONG},
    {{100, 60, 0}, STATE_WRONG},
    {{100, 60, 0}, STATE_WRONG},
    {{100, 60, 0}, STATE_WRONG},
    {{100, 60, 0}, STATE_WRONG},
    {{100, 60, 0}, STATE_WRONG},
    {{100, 60, 0}, STATE_WRONG},
    {{100, 60, 0}, STATE_WRONG},
    {{100, 60, 0}, STATE_WRONG},
    {{100, 60, 0}, STATE_WRONG},
    {{100, 60, 0}, STATE_WRONG},
    {{100, 60, 0}, STATE_WRONG},
    {{100, 60, 0}, STATE_WRONG},
    {{100, 60, 0}, STATE_WRONG},
    {{100, 60, 0}, STATE_WRONG},
    {{100, 60, 0}, STATE_WRONG},
    {{100, 60, 0}, STATE_WRONG},
    {{100, 60, 0}, STATE_WRONG},
    {{100, 60, 0}, STATE_WRONG},
    {{100, 60, 0}, STATE_WRONG},
    {{100, 60, 0}, STATE_WRONG},
    {{100, 60, 0}, STATE_WRONG},
    {{100, 60, 0}, STATE_WRONG},
    {{100, 60, 0}, STATE_WRONG},
    {{100, 60, 0}, STATE_WRONG},
    {{100, 60, 0}, STATE_WRONG},
    {{100, 60, 0}, STATE_WRONG},
    {{100, 60, 0}, STATE_WRONG},
    {{100, 60, 0}, STATE_WRONG},
    {{100, 60, 0}, STATE_WRONG},
    {{100, 60, 0}, STATE_WRONG},
    {{100, 60, 0}, STATE_WRONG},
    {{100, 60, 0}, STATE_WRONG},
    {{100, 60, 0}, STATE_WRONG},
    {{100, 60, 0}, STATE_WRONG},
    {{100, 60, 0}, STATE_WRONG},
    {{100, 60, 0}, STATE_WRONG},
    {{100, 60, 0}, STATE_WRONG},
    {{100, 60, 0}, STATE_WRONG},
    {{100, 60, 0}, STATE_WRONG},
    {{100, 100, 0}, STATE_UNKNOWN},
    {{100, 100, 0}, STATE_UNKNOWN},
    {{100, 100, 0}, STATE_UNKNOWN},
    {{100, 100, 0}, STATE_UNKNOWN},
    {{100, 100, 0}, STATE_UNKNOWN},
    {{100, 100, 0}, STATE_UNKNOWN},
    {{100, 100, 0}, STATE_UNKNOWN},
    {{100, 100, 0}, STATE_UNKNOWN},
    {{100, 100, 0}, STATE_UNKNOWN},
    {{100, 100, 0}, STATE_UNKNOWN},
    {{100, 100, 0}, STATE_UNKNOWN},
    {{100, 98, 0}, STATE_RIGHT},
    {{100, 96, 0}, STATE_RIGHT},
    {{100, 94, 0}, STATE_RIGHT},
    {{100, 92, 0}, STATE_RIGHT},
    {{100, 90, 0}, STATE_RIGHT},
    {{100, 88, 0}, STATE_RIGHT},
    {{100, 86, 0}, STATE_RIGHT},
    {{100, 84, 0}, STATE_RIGHT},
    {{100, 82, 0}, STATE_RIGHT},
    {{100, 80, 0}, STATE_RIGHT},
    {{100, 78, 0}, STATE_RIGHT},
    {{100, 76, 0}, STATE_RIGHT},
    {{100, 74, 0}, STATE_RIGHT},
    {{100, 72, 0}, STATE_RIGHT},
    {{100, 70, 0}, STATE_RIGHT},
    {{100, 68, 0}, STATE_RIGHT},
    {{100, 66, 0}, STATE_RIGHT},
    {{100, 64, 0}, STATE_RIGHT},
    {{100, 62, 0}, STATE_RIGHT},
    {{100, 60, 0}, STATE_RIGHT},
    {{100, 60, 0}, STATE_RIGHT},
    {{100, 60, 0}, STATE_RIGHT},
    {{100, 60, 0}, STATE_RIGHT},
    {{100, 60, 0}, STATE_RIGHT},
    {{100, 60, 0}, STATE_RIGHT},
    {{100, 60, 0}, STATE_RIGHT},
    {{100, 60, 0}, STATE_RIGHT},
    {{100, 60, 0}, STATE_RIGHT},
    {{100, 60, 0}, STATE_RIGHT},
    {{100, 60, 0}, STATE_RIGHT},
    {{100, 60, 0}, STATE_RIGHT},
    {{100, 60, 0}, STATE_RIGHT},
    {{100, 60, 0}, STATE_RIGHT},
    {{100, 60, 0}, STATE_RIGHT},
    {{100, 60, 0}, STATE_RIGHT},
    {{100, 60, 0}, STATE_RIGHT},
    {{100, 60, 0}, STATE_RIGHT},
    {{100, 60, 0}, STATE_RIGHT},
    {{100, 60, 0}, STATE_RIGHT},
    {{100, 60, 0}, STATE_RIGHT},
    {{100, 60, 0}, STATE_RIGHT},
    {{100, 60, 0}, STATE_RIGHT},
    {{100, 60, 0}, STATE_RIGHT},
    {{100, 60, 0}, STATE_RIGHT},
    {{100, 60, 0}, STATE_RIGHT},
    {{100, 60, 0}, STATE_RIGHT},
    {{100, 60, 0}, STATE_RIGHT},
    {{100, 60, 0}, STATE_RIGHT},
    {{100, 60, 0}, STATE_RIGHT},
    {{100, 60, 0}, STATE_RIGHT},
    {{100, 60, 0}, STATE_RIGHT},
    {{100, 0, 0}, STATE_RIGHT},
    {{100, 0, 0}, STATE_RIGHT},
    {{0, 0, 0}, STATE_RIGHT},
};
const frame_t look_switch_fuck[] = {
    // { hatch, finger, bonus_hatch, expected_state}
    {{0, 0, 0}, STATE_WRONG},
    {{100, 60, 0}, STATE_WRONG},
    {{100, 60, 0}, STATE_WRONG},
    {{100, 60, 0}, STATE_WRONG},
    {{100, 60, 0}, STATE_WRONG},
    {{100, 60, 0}, STATE_WRONG},
    {{100, 60, 0}, STATE_WRONG},
    {{100, 60, 0}, STATE_WRONG},
    {{100, 60, 0}, STATE_WRONG},
    {{100, 60, 0}, STATE_WRONG},
    {{100, 60, 0}, STATE_WRONG},
    {{100, 60, 0}, STATE_WRONG},
    {{100, 60, 0}, STATE_WRONG},
    {{100, 60, 0}, STATE_WRONG},
    {{100, 60, 0}, STATE_WRONG},
    {{100, 60, 0}, STATE_WRONG},
    {{100, 60, 0}, STATE_WRONG},
    {{100, 60, 0}, STATE_WRONG},
    {{100, 60, 0}, STATE_WRONG},
    {{100, 60, 0}, STATE_WRONG},
    {{100, 60, 0}, STATE_WRONG},
    {{100, 60, 0}, STATE_WRONG},
    {{100, 60, 0}, STATE_WRONG},
    {{100, 60, 0}, STATE_WRONG},
    {{100, 60, 0}, STATE_WRONG},
    {{100, 60, 0}, STATE_WRONG},
    {{100, 60, 0}, STATE_WRONG},
    {{100, 60, 0}, STATE_WRONG},
    {{100, 60, 0}, STATE_WRONG},
    {{100, 60, 0}, STATE_WRONG},
    {{100, 60, 0}, STATE_WRONG},
    {{100, 60, 0}, STATE_WRONG},
    {{100, 60, 0}, STATE_WRONG},
    {{100, 60, 0}, STATE_WRONG},
    {{100, 60, 0}, STATE_WRONG},
    {{100, 60, 0}, STATE_WRONG},
    {{100, 60, 0}, STATE_WRONG},
    {{100, 60, 0}, STATE_WRONG},
    {{100, 60, 0}, STATE_WRONG},
    {{100, 60, 0}, STATE_WRONG},
    {{100, 60, 0}, STATE_WRONG},
    {{100, 60, 0}, STATE_WRONG},
    {{100, 60, 0}, STATE_WRONG},
    {{100, 60, 0}, STATE_WRONG},
    {{100, 60, 0}, STATE_WRONG},
    {{100, 60, 0}, STATE_WRONG},
    {{100, 60, 0}, STATE_WRONG},
    {{100, 60, 0}, STATE_WRONG},
    {{100, 60, 0}, STATE_WRONG},
    {{100, 60, 0}, STATE_WRONG},
    {{100, 60, 0}, STATE_WRONG},
    {{100, 100, 0}, STATE_UNKNOWN},
    {{100, 100, 0}, STATE_UNKNOWN},
    {{100, 100, 0}, STATE_UNKNOWN},
    {{100, 100, 0}, STATE_UNKNOWN},
    {{100, 100, 0}, STATE_UNKNOWN},
    {{100, 100, 0}, STATE_UNKNOWN},
    {{100, 100, 0}, STATE_UNKNOWN},
    {{100, 100, 0}, STATE_UNKNOWN},
    {{100, 100, 0}, STATE_UNKNOWN},
    {{100, 100, 0}, STATE_UNKNOWN},
    {{100, 100, 0}, STATE_UNKNOWN},
    {{100, 98, 0}, STATE_RIGHT},
    {{100, 96, 0}, STATE_RIGHT},
    {{100, 94, 0}, STATE_RIGHT},
    {{100, 92, 0}, STATE_RIGHT},
    {{100, 90, 0}, STATE_RIGHT},
    {{100, 88, 0}, STATE_RIGHT},
    {{100, 86, 0}, STATE_RIGHT},
    {{100, 84, 0}, STATE_RIGHT},
    {{100, 82, 0}, STATE_RIGHT},
    {{100, 80, 0}, STATE_RIGHT},
    {{100, 78, 0}, STATE_RIGHT},
    {{100, 76, 0}, STATE_RIGHT},
    {{100, 74, 0}, STATE_RIGHT},
    {{100, 72, 0}, STATE_RIGHT},
    {{100, 70, 0}, STATE_RIGHT},
    {{100, 68, 0}, STATE_RIGHT},
    {{100, 66, 0}, STATE_RIGHT},
    {{100, 64, 0}, STATE_RIGHT},
    {{100, 62, 0}, STATE_RIGHT},
    {{100, 60, 100}, STATE_RIGHT},
    {{100, 60, 100}, STATE_RIGHT},
    {{100, 60, 100}, STATE_RIGHT},
    {{100, 60, 100}, STATE_RIGHT},
    {{100, 60, 100}, STATE_RIGHT},
    {{100, 60, 100}, STATE_RIGHT},
    {{100, 60, 100}, STATE_RIGHT},
    {{100, 60, 100}, STATE_RIGHT},
    {{100, 60, 100}, STATE_RIGHT},
    {{100, 60, 100}, STATE_RIGHT},
    {{100, 60, 100}, STATE_RIGHT},
    {{100, 60, 100}, STATE_RIGHT},
    {{100, 60, 100}, STATE_RIGHT},
    {{100, 60, 100}, STATE_RIGHT},
    {{100, 60, 100}, STATE_RIGHT},
    {{100, 60, 100}, STATE_RIGHT},
    {{100, 60, 100}, STATE_RIGHT},
    {{100, 60, 100}, STATE_RIGHT},
    {{100, 60, 100}, STATE_RIGHT},
    {{100, 60, 100}, STATE_RIGHT},
    {{100, 60, 100}, STATE_RIGHT},
    {{100, 60, 100}, STATE_RIGHT},
    {{100, 60, 100}, STATE_RIGHT},
    {{100, 60, 100}, STATE_RIGHT},
    {{100, 60, 100}, STATE_RIGHT},
    {{100, 60, 100}, STATE_RIGHT},
    {{100, 60, 100}, STATE_RIGHT},
    {{100, 60, 100}, STATE_RIGHT},
    {{100, 60, 100}, STATE_RIGHT},
    {{100, 60, 100}, STATE_RIGHT},
    {{100, 60, 100}, STATE_RIGHT},
    {{100, 60, 100}, STATE_RIGHT},
    {{100, 0, 0}, STATE_RIGHT},
    {{100, 0, 0}, STATE_RIGHT},
    {{0, 0, 0}, STATE_RIGHT},
};
/*******************************************************************************
 * Range Data
 ******************************************************************************/
const frame_t no_move[] = {
    // { hatch, finger, bonus_hatch, expected_state}
    {{0, 0, 0}, STATE_UNKNOWN},
    {{0, 0, 0}, STATE_UNKNOWN},
    {{0, 0, 0}, STATE_UNKNOWN},
    {{0, 0, 0}, STATE_UNKNOWN},
    {{0, 0, 0}, STATE_UNKNOWN},
    {{0, 0, 0}, STATE_UNKNOWN},
    {{0, 0, 0}, STATE_UNKNOWN},
    {{0, 0, 0}, STATE_UNKNOWN},
    {{0, 0, 0}, STATE_UNKNOWN},
    {{0, 0, 0}, STATE_UNKNOWN},
    {{0, 0, 0}, STATE_UNKNOWN},
    {{0, 0, 0}, STATE_UNKNOWN},
    {{0, 0, 0}, STATE_UNKNOWN},
};
const frame_t simple_look[] = {
    // { hatch, finger, bonus_hatch, expected_state}
    {{0, 0, 0}, STATE_WRONG},
    {{30, 0, 0}, STATE_WRONG | (1 << STATE_LED)},
    {{30, 0, 0}, STATE_UNKNOWN | (1 << STATE_LED)},
    {{30, 0, 0}, STATE_UNKNOWN | (1 << STATE_LED)},
    {{30, 0, 0}, STATE_UNKNOWN | (1 << STATE_LED)},
    {{30, 0, 0}, STATE_UNKNOWN | (1 << STATE_LED)},
    {{30, 0, 0}, STATE_UNKNOWN | (1 << STATE_LED)},
    {{30, 0, 0}, STATE_UNKNOWN | (1 << STATE_LED)},
    {{30, 0, 0}, STATE_UNKNOWN | (1 << STATE_LED)},
    {{30, 0, 0}, STATE_UNKNOWN | (1 << STATE_LED)},
    {{30, 0, 0}, STATE_UNKNOWN | (1 << STATE_LED)},
    {{30, 0, 0}, STATE_RIGHT | (1 << STATE_LED)},
    {{26, 0, 0}, STATE_RIGHT},
    {{22, 0, 0}, STATE_RIGHT},
    {{18, 0, 0}, STATE_RIGHT},
    {{14, 0, 0}, STATE_RIGHT},
    {{10, 0, 0}, STATE_RIGHT},
    {{8, 0, 0}, STATE_RIGHT},
    {{6, 0, 0}, STATE_RIGHT},
    {{4, 0, 0}, STATE_RIGHT},
    {{2, 0, 0}, STATE_RIGHT},
    {{0, 0, 0}, STATE_RIGHT},
};

#endif /* USELESS_DATA_H */
