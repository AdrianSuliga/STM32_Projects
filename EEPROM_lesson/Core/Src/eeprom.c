/*
 * eeprom.c
 *
 *  Created on: Aug 26, 2024
 *      Author: arima
 */

#include "eeprom.h"
#include "i2c.h"

#define EEPROM_ADDR 0xA0
#define WRITE_TIMEOUT 6

static uint32_t last_write;

void eeprom_wait(void)
{
	while (HAL_GetTick() - last_write <= WRITE_TIMEOUT)
	{

	}
}

HAL_StatusTypeDef eeprom_read(uint32_t addr, void* data, uint32_t size)
{
	eeprom_wait();
	return HAL_I2C_Mem_Read(&hi2c1, EEPROM_ADDR, addr, 1, data, size, HAL_MAX_DELAY);
}

HAL_StatusTypeDef eeprom_write(uint32_t addr, const void* data, uint32_t size)
{
	HAL_StatusTypeDef result;

	eeprom_wait();
	result = HAL_I2C_Mem_Write(&hi2c1, EEPROM_ADDR, addr, 1, (void*)data, size, HAL_MAX_DELAY);
	last_write = HAL_GetTick();

	return result;
}
