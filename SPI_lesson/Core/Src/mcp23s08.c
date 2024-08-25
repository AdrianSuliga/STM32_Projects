/*
 * mcp23s08.c
 *
 *  Created on: Aug 25, 2024
 *      Author: arima
 */

#include "mcp23s08.h"
#include "spi.h"

uint8_t MCP_Register_Read(uint8_t reg)
{
	uint8_t data[2] = {0x41, reg};
	uint8_t value = -1;

	HAL_GPIO_WritePin(IOEXP_CS_GPIO_Port, IOEXP_CS_Pin, GPIO_PIN_RESET);
	HAL_SPI_Transmit(&hspi2, data, 2, HAL_MAX_DELAY);
	HAL_SPI_Receive(&hspi2, &value, 1, HAL_MAX_DELAY);
	HAL_GPIO_WritePin(IOEXP_CS_GPIO_Port, IOEXP_CS_Pin, GPIO_PIN_SET);

	return value;
}

uint8_t MCP_GPIO_ReadPin(uint8_t pin)
{
	uint8_t pin_settings = MCP_Register_Read(MCP_IODIR);
	uint8_t pin_mode = (pin_settings >> pin) & 1;

	if (pin_mode != 1)
		return -1;

	uint8_t register_value = MCP_Register_Read(MCP_GPIO);
	uint8_t pin_state = (register_value >> pin) & 1;
	return pin_state;
}

void MCP_Register_Write(uint8_t reg, uint8_t value)
{
	uint8_t data[3] = {0x40, reg, value};

	HAL_GPIO_WritePin(IOEXP_CS_GPIO_Port, IOEXP_CS_Pin, GPIO_PIN_RESET);
	HAL_SPI_Transmit(&hspi2, data, 3, HAL_MAX_DELAY);
	HAL_GPIO_WritePin(IOEXP_CS_GPIO_Port, IOEXP_CS_Pin, GPIO_PIN_SET);
}

void MCP_GPIO_WritePin(uint8_t pin, uint8_t value)
{
	uint8_t current_register_state = MCP_Register_Read(MCP_OLAT);
	uint8_t new_register_state = 0;

	if (value == 1)
		new_register_state = current_register_state | (1 << pin);
	if (value == 0)
		new_register_state = current_register_state & ~(1 << pin);

	MCP_Register_Write(MCP_OLAT, new_register_state);
}








