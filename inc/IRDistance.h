/**
 * @file      IRDistance.h
 * @brief     Take infrared distance measurements
 * @details   Provide mid-level functions that convert raw ADC
 * values from the GP2Y0A21YK0F infrared distance sensors to
 * distances in mm.
 * @version   TI-RSLK MAX v1.1
 * @author    Daniel Valvano and Jonathan Valvano
 * @copyright Copyright 2019 by Jonathan W. Valvano, valvano@mail.utexas.edu,
 * @warning   AS-IS
 * @note      For more information see  http://users.ece.utexas.edu/~valvano/
 * @date      June 28, 2019
<table>
<caption id="ADCpins2">ADC pins used on the TI-RSLK MAX</caption>
<tr><th>Pin  <th>ADC channel<th>Sensor
<tr><td>P9.0 <td>A17<th>right GP2Y0A21YK0F
<tr><td>P6.1 <td>A14<th>center GP2Y0A21YK0F
<tr><td>P9.1 <td>A16<th>left GP2Y0A21YK0F
</table>
 ******************************************************************************/

/* This example accompanies the book
   "Embedded Systems: Introduction to Robotics,
   Jonathan W. Valvano, ISBN: 9781074544300, copyright (c) 2019
 For more information about my classes, my research, and my books, see
 http://users.ece.utexas.edu/~valvano/

Simplified BSD License (FreeBSD License)
Copyright (c) 2017, Jonathan Valvano, All rights reserved.

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

// 5V connected to all three GP2Y0A21YK0F Vcc's (+5V)
// 5V connected to positive side of three 10 uF capacitors physically near the sensors
// ground connected to all threeGP2Y0A21YK0F grounds and MSP432 ground
// ground connected to negative side of all three 10 uF capacitors
// MSP432 P9.0 (J5) (analog input to MSP432) connected to right GP2Y0A21YK0F Vout
// MSP432 P4.1 (J1.5) (analog input to MSP432) connected to center GP2Y0A21YK0F Vout
// MSP432 P9.1 (J5) (analog input to MSP432) connected to left GP2Y0A21YK0F Vout

/*!
 * @defgroup RSLK_Input_Output
 * @brief
 * @{*/
#ifndef IRDISTANCE_H_
#define IRDISTANCE_H_


/**
 * Convert ADC sample into distance for the GP2Y0A21YK0F
 * infrared distance sensor.  Conversion uses a calibration formula<br>
 * d = m/(n-c) + r,
 * where n is the adc_value, d is the distance from the center of the robot to the wall,
 * r is the distance between the center of the robot and the sensor,
 * and m and r are calibration constants.
 * @param adc_value is the 14-bit ADC sample 0 to 16383
 * @return distance from robot center to left wall (units mm)
 * @brief  Calculate the distance in mm given the 14-bit ADC value.
 */
int32_t LeftConvert(uint32_t adc_value);

/**
 * Convert ADC sample into distance for the GP2Y0A21YK0F
 * infrared distance sensor.  Conversion uses a calibration formula<br>
 * d = m/(n-c) + r,
 * where n is the adc_value, d is the distance from the center of the robot to the wall,
 * r is the distance between the center of the robot and the sensor,
 * and m and r are calibration constants.
 * @param adc_value is the 14-bit ADC sample 0 to 16383
 * @return distance from robot center to center wall (units mm)
 * @brief  Calculate the distance in mm given the 14-bit ADC value.
 */
int32_t CenterConvert(uint32_t adc_value);

/**
 * Convert ADC sample into distance for the GP2Y0A21YK0F
 * infrared distance sensor.  Conversion uses a calibration formula<br>
 * d = m/(n-c) + r,
 * where n is the adc_value, d is the distance from the center of the robot to the wall,
 * r is the distance between the center of the robot and the sensor,
 * and m and r are calibration constants.
 * @param adc_value is the 14-bit ADC sample 0 to 16383
 * @return distance from robot center to right wall (units mm)
 * @brief  Calculate the distance in mm given the 14-bit ADC value.
 */
int32_t RightConvert(uint32_t adc_value);      // returns right distance in mm

#endif /* IRDISTANCE_H_ */
