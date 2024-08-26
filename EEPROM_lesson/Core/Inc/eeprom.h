/*
 * eeprom.h
 *
 *  Created on: Aug 26, 2024
 *      Author: arima
 */

#ifndef INC_EEPROM_H_
#define INC_EEPROM_H_

#include "stm32f1xx.h"

// Delay necessary to finish writing
void eeprom_wait(void);

// Read data from EEPROM memory
// addr - starting address in memory
// data - buffer where data will be held
// size - size of read data
// return - HAL_OK if data was read correctly
HAL_StatusTypeDef eeprom_read(uint32_t addr, void* data, uint32_t size);

// Write data to EEPROM memory
// addr starting address in memory
// data - data to write
// size - number of bytes to write
// return - HAL_OK if data was written successfully
HAL_StatusTypeDef eeprom_write(uint32_t addr, const void* data, uint32_t size);

#endif /* INC_EEPROM_H_ */
