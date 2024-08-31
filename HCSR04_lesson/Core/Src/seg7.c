/*
 * seg7.c
 *
 *  Created on: Aug 31, 2024
 *      Author: arima
 */
#include <stdbool.h>
#include "seg7.h"
#include "gpio.h"

static uint32_t actual_value;
static uint32_t active_digit;

static void Set_Output(uint8_t mask)
{
	HAL_GPIO_WritePin(SEG_A_GPIO_Port, SEG_A_Pin, mask & 0x01);
	HAL_GPIO_WritePin(SEG_B_GPIO_Port, SEG_B_Pin, mask & 0x02);
	HAL_GPIO_WritePin(SEG_C_GPIO_Port, SEG_C_Pin, mask & 0x04);
	HAL_GPIO_WritePin(SEG_D_GPIO_Port, SEG_D_Pin, mask & 0x08);
	HAL_GPIO_WritePin(SEG_E_GPIO_Port, SEG_E_Pin, mask & 0x10);
	HAL_GPIO_WritePin(SEG_F_GPIO_Port, SEG_F_Pin, mask & 0x20);
	HAL_GPIO_WritePin(SEG_G_GPIO_Port, SEG_G_Pin, mask & 0x40);
}

void SEG7_Show_Digit(uint32_t value)
{
	const uint8_t digit[] = {
			0b0111111,
			0b0000110,
			0b1011011,
			0b1001111,
			0b1100110,
			0b1101101,
			0b1111101,
			0b0000111,
			0b1111111,
			0b1101111,
	};
	const uint8_t special_sign = 0b1000000;

	if (0 <= value && value <= 99)
		Set_Output(digit[value % 10]);
	else
		Set_Output(special_sign);
}

void SEG7_Show(uint32_t value)
{
	actual_value = value;
}

void SEG7_Update(void)
{
	HAL_GPIO_WritePin(SEG_1_GPIO_Port, SEG_1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, GPIO_PIN_SET);

	if (actual_value < 0 || 99 < actual_value) {
		SEG7_Show_Digit(actual_value);
		HAL_GPIO_WritePin(SEG_1_GPIO_Port, SEG_1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, GPIO_PIN_RESET);
	} else {
		switch (active_digit) {
		case 0:
			SEG7_Show_Digit(actual_value);
			HAL_GPIO_WritePin(SEG_1_GPIO_Port, SEG_1_Pin, GPIO_PIN_RESET);
			active_digit = 1;
			break;
		case 1:
			SEG7_Show_Digit(actual_value / 10);
			HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, GPIO_PIN_RESET);
			active_digit = 0;
			break;
		default:
			break;
		}
	}
}
