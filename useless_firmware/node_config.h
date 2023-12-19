/******************************************************************************
 * @file node_config.h
 * @brief This file allow you to use standard preprocessor definitions to
 *        configure your project, Luos and Luos HAL libraries
 *
 *   # Introduction
 *     This file is for the luos user. You may here configure your project and
 *     define your custom Luos service and custom Luos command for your product
 *
 *     Luos libraries offer a minimal standard configuration to optimize
 *     memory usage. In some case you have to modify standard value to fit
 *     with your need concerning among of data transiting through the network
 *     or network speed for example
 *
 *     Luos libraries can be use with a lot a MCU family. Luos compagny give you
 *     a default configuration, for specific MCU family, in robus_hal_config.h.
 *     This configuration can be modify here to fit with you design by
 *     preprocessor definitions of MCU Hardware needs
 *
 *   # Usage
 *      This file should be place a the root folder of your project and include
 *      where build flag preprocessor definitions are define in your IDE
 *      -include node_config.h
 *
 * @author Luos
 * @version 0.0.0
 ******************************************************************************/
#ifndef _NODE_CONFIG_H_
#define _NODE_CONFIG_H_

/*******************************************************************************
 * PROJECT DEFINITION
 *******************************************************************************/

/*******************************************************************************
 * LUOS LIBRARY DEFINITION
 *******************************************************************************
 *    Define                | Default Value              | Description
 *    :---------------------|------------------------------------------------------
 *    MAX_LOCAL_SERVICE_NUMBER    |              5             | Service number in the node
 *    MAX_NODE_NUMBER.      |              20            | Node number in the device
 *    MSG_BUFFER_SIZE       | 3*SIZE_MSG_MAX (405 Bytes) | Size in byte of the Luos buffer TX and RX
 *    MAX_MSG_NB            |   2*MAX_LOCAL_SERVICE_NUMBER     | Message number in Luos buffer
 *    MAX_NODE_NUMBER       |              20            | Node number in the device
 *    MAX_SERVICE_NUMBER    |              20            | Service number in the device
 *    NBR_PORT              |              2             | PTP Branch number Max 8
 *    NBR_RETRY             |             10             | Send Retry number in case of NACK or collision
 ******************************************************************************/
#define MAX_LOCAL_SERVICE_NUMBER 5
#define MAX_MSG_NB               20
#define MSG_BUFFER_SIZE          512

/*******************************************************************************
 * USELESS BEHAVIOR DEFINITION
 *******************************************************************************/
// ******************* Motor movement amplitude configuration *******************
// To calibrate the motors angle amplitude, please follow this procedure:
// 1. Unmount all motors output shaft from the robot moving parts
// 2. Set all motors min and max angle to 0.0f and 180.0f
// 3. Flash the board and connect to it trough Pyluos
// 4. Check the motor direction one by one, and switch it if needed in this configuration file. (smallest value should close the hatch or the finger)
// 5. Flash the board and connect to it trough Pyluos
// For each motor:
// 6. Trough Pyluos, set the motor to 90°, mount the output shaft to the robot moving parts
// 7. Test the min and max limit of the motor, then put it on this file
// For the hatcha nd finger:
// 8. Close the hatch and move the finger to slightly touch the hatch, save the finger angle in the FINGER_REACH_HATCH
// 9. Open the hatch and move the finger to be as close as possible from the hatch surface
// 10. Move the Hatch to slightly touch the finger, save the hatch angle in the HATCH_MIN_OPEN
// 11. Flash the board and you should be good to go
#define HATCH_MIN_ANGLE 77.0f
#define HATCH_MAX_ANGLE 110.0f
#define HATCH_DIRECTION 0

#define FINGER_MIN_ANGLE 30.0f
#define FINGER_MAX_ANGLE 155.0f
#define FINGER_DIRECTION 0

#define BONUS_HATCH_MIN_ANGLE 40.0f
#define BONUS_HATCH_MAX_ANGLE 125.0f
#define BONUS_HATCH_DIRECTION 0

#define FINGER_REACH_HATCH 36.0f
#define HATCH_MIN_OPEN     100.0f

/*******************************************************************************
 * Leo's config
 *******************************************************************************/
// #define HATCH_MIN_ANGLE 66.0f
// #define HATCH_MAX_ANGLE 132.0f
// #define HATCH_DIRECTION 0

// #define FINGER_MIN_ANGLE 10.0f
// #define FINGER_MAX_ANGLE 135.0f
// #define FINGER_DIRECTION 0

// #define BONUS_HATCH_MIN_ANGLE 27.0f
// #define BONUS_HATCH_MAX_ANGLE 130.0f
// #define BONUS_HATCH_DIRECTION 0

// #define FINGER_REACH_HATCH 24.0f
// #define HATCH_MIN_OPEN     125.0f

#endif /* _NODE_CONFIG_H_ */
