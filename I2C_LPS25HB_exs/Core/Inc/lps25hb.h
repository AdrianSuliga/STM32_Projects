/*
 * lps25hb.h
 *
 *  Created on: Aug 30, 2024
 *      Author: arima
 */

#ifndef INC_LPS25HB_H_
#define INC_LPS25HB_H_

#include <stm32f1xx.h>

// Initialization of LPS25HB sensor
// Wake up and set up automatic measurements
// Also, write reference pressure to REF register
// return - HAL_OK or HAL_ERROR
HAL_StatusTypeDef LPS25HB_Init(void);

// Calibrate pressure sensor
// value - correction
void LPS25HB_Set_Calibration(uint16_t value);

// Read temperature
// return - temperature in Celsius degrees
float LPS25HB_Read_Temp(void);

// Read pressure
// return - pressure in hPa
float LPS25HB_Read_Pressure(void);

// Read pressure difference compared to p0
// return - pressure / p0
float LPS25HB_Read_Pressure_Difference(void);

#endif /* INC_LPS25HB_H_ */
