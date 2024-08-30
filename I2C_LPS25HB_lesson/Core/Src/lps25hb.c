/*
 * lps25hb.c
 *
 *  Created on: Aug 30, 2024
 *      Author: arima
 */

#include "lps25hb.h"
#include "i2c.h"

#define LPS25HB_ADDR        0xBA

#define LPS25HB_WHO_AM_I 		0x0F
#define LPS25HB_CTRL_REG1 		0x20
#define LPS25HB_CTRL_REG2 		0x21
#define LPS25HB_CTRL_REG3 		0x22
#define LPS25HB_CTRL_REG4 		0x23
#define LPS25HB_PRESS_OUT_XL 	0x28
#define LPS25HB_PRESS_OUT_L 	0x29
#define LPS25HB_PRESS_OUT_H 	0x2A
#define LPS25HB_TEMP_OUT_L 		0x2B
#define LPS25HB_TEMP_OUT_H 		0x2C
#define LPS25HB_RPDS_L 			0x39
#define LPS25HB_RPDS_H 			0x3A
#define LPS25HB_FIFO_CTRL		0x2E

#define TIMEOUT                 100

static uint8_t LPS25HB_Read_Register(uint8_t reg)
{
	uint8_t value;
	HAL_I2C_Mem_Read(&hi2c1, LPS25HB_ADDR, reg, 1, &value, sizeof(value), TIMEOUT);
	return value;
}

static void LPS25HB_Write_Register(uint8_t reg, uint8_t value)
{
	HAL_I2C_Mem_Write(&hi2c1, LPS25HB_ADDR, reg, 1, &value, sizeof(value), TIMEOUT);
}

HAL_StatusTypeDef LPS25HB_Init(void)
{
	if (LPS25HB_Read_Register(0x0F) != 0xBD)
		return HAL_ERROR;

	LPS25HB_Write_Register(LPS25HB_CTRL_REG1, 0xC0);
	LPS25HB_Write_Register(LPS25HB_CTRL_REG2, 0x40);
	LPS25HB_Write_Register(LPS25HB_FIFO_CTRL, 0xDF);

	return HAL_OK;
}

void LPS25HB_Set_Calibration(uint16_t value)
{
	LPS25HB_Write_Register(LPS25HB_RPDS_L, value);
	LPS25HB_Write_Register(LPS25HB_RPDS_H, value >> 8);
}

float LPS25HB_Read_Temp(void)
{
	int16_t temp = 0;

	if (HAL_I2C_Mem_Read(&hi2c1, LPS25HB_ADDR, LPS25HB_TEMP_OUT_L | 0x80, 1, (uint8_t*)&temp, sizeof(temp), TIMEOUT) != HAL_OK)
		Error_Handler();

	return 42.5f + temp / 480.0f;
}

float LPS25HB_Read_Pressure(void)
{
	int32_t pressure = 0;

	if (HAL_I2C_Mem_Read(&hi2c1, LPS25HB_ADDR, LPS25HB_PRESS_OUT_XL | 0x80, 1, (uint8_t*)&pressure, 3, TIMEOUT) != HAL_OK)
		Error_Handler();

	return pressure / 4096.0f;
}





