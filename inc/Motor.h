/**
 * @file      Motor.h
 * @brief     Set motor speed and direction
 * @details   Provide mid-level functions that initialize ports and
 * set motor speeds to move the robot.<br>

 * @version   TI-RSLK MAX v1.1
 * @author    Daniel Valvano and Jonathan Valvano
 * @copyright Copyright 2019 by Jonathan W. Valvano, valvano@mail.utexas.edu,
 * @warning   AS-IS
 * @note      For more information see  http://users.ece.utexas.edu/~valvano/
 * @date      June 28, 2019
<table>
<caption id="motorconnections1">TI-RSLK MAX v1.1 motor connections</caption>
<tr><th>Pin<th>J<th>MSP432<th>Motor function
<tr><td>P5.4<td>J3.29<td>GPIO<td>Left motor direction
<tr><td>P2.7<td>J4.40<td>TA0CCP4<td>Left motor PWM
<tr><td>P3.7<td>J4.31<td>GPIO<td>Left motor enable
<tr><td>P5.5<td>J3.30<td>GPIO<td>Right motor direction
<tr><td>P2.6<td>J4.39<td>TA0CCP3<td>Right motor PWM
<tr><td>P3.6<td>J2.11<td>GPIO<td>Right motor enable
</table>
 ******************************************************************************/

/* This example accompanies the book
   "Embedded Systems: Introduction to Robotics,
   Jonathan W. Valvano, ISBN: 9781074544300, copyright (c) 2019
 For more information about my classes, my research, and my books, see
 http://users.ece.utexas.edu/~valvano/

Simplified BSD License (FreeBSD License)
Copyright (c) 2019, Jonathan Valvano, All rights reserved.

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice,
   this list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE
USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

The views and conclusions contained in the software and documentation are
those of the authors and should not be interpreted as representing official
policies, either expressed or implied, of the FreeBSD Project.
*/


/*!
 * @defgroup RSLK_Input_Output
 * @brief
 * @{*/

#ifndef MOTOR_H_
#define MOTOR_H_


/**
 * Initialize GPIO pins for output, which will be
 * used to control the direction of the motors and
 * to enable or disable the drivers.
 * The motors are initially stopped, the drivers
 * are initially powered down, and the PWM speed
 * control is uninitialized.
 * @param none
 * @return none
 * @brief  Initialize motor interface
 */
void Motor_Init(void);


/**
 * Stop the motors, power down the drivers, and
 * set the PWM speed control to 0% duty cycle.
 * @param none
 * @return none
 * @brief  Stop the robot
 */
void Motor_Brake(void);


/**
 * This function is the same as Motor_Brake,
 * but it takes two dummy variables to make it
 * compatible with other motor functions.
 * @param dummy1 unused dummy variable
 * @param dummy2 unused dummy variable
 * @return none
 * @note Assumes Motor_Init() has been called
 * @brief Stop the robot
 */
void Motor_Stop(uint16_t dummy1, uint16_t dummy2);


/**
 * Stop the motors, power down the drivers, and
 * set the PWM speed control to 0% duty cycle.
 * @param none
 * @return none
 * @brief  Coast the robot
 */
void Motor_Coast(void);

/**
 * Drive the robot forward by running left and
 * right wheels forward with the given duty
 * cycles.
 * @param leftDuty_permil  duty cycle of left wheel (0 to 999)
 * @param rightDuty_permil duty cycle of right wheel (0 to 999)
 * @return none
 * @note Assumes Motor_Init() has been called
 * @brief  Drive the robot forward
 */
void Motor_Forward(uint16_t leftDuty_permil, uint16_t rightDuty_permil);

/**
 * Turn the robot to the right by running the
 * left wheel forward and the right wheel
 * backward with the given duty cycles.
 * @param leftDuty_permil  duty cycle of left wheel (0 to 999)
 * @param rightDuty_permil duty cycle of right wheel (0 to 999)
 * @return none
 * @note Assumes Motor_Init() has been called
 * @brief  Turn the robot to the right
 */
void Motor_TurnRight(uint16_t leftDuty_permil, uint16_t rightDuty_permil);

/**
 * Turn the robot to the left by running the
 * left wheel backward and the right wheel
 * forward with the given duty cycles.
 * @param leftDuty_permil  duty cycle of left wheel (0 to 999)
 * @param rightDuty_permil duty cycle of right wheel (0 to 999)
 * @return none
 * @note Assumes Motor_Init() has been called
 * @brief  Turn the robot to the left
 */
void Motor_TurnLeft(uint16_t leftDuty_permil, uint16_t rightDuty_permil);

/**
 * Drive the robot backward by running left and
 * right wheels backward with the given duty
 * cycles.
 * @param leftDuty_permil  duty cycle of left wheel (0 to 999)
 * @param rightDuty_permil duty cycle of right wheel (0 to 999)
 * @return none
 * @note Assumes Motor_Init() has been called
 * @brief  Drive the robot backward
 */
void Motor_Backward(uint16_t leftDuty_permil, uint16_t rightDuty_permil);

#endif /* MOTOR_H_ */
