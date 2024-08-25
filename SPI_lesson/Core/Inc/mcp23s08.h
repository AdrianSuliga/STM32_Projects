/*
 * mcp23s08.h
 *
 *  Created on: Aug 25, 2024
 *      Author: arima
 */

#ifndef INC_MCP23S08_H_
#define INC_MCP23S08_H_

#include "stdint.h"

// Registers on MCP23S08
#define MCP_IODIR 0x00
#define MCP_IPOL 0x01
#define MCP_GPINTEN 0x02
#define MCP_DEFVAL 0x03
#define MCP_INTCON 0x04
#define MCP_IOCON 0x05
#define MCP_GPPU 0x06
#define MCP_INTF 0x07
#define MCP_INTCAP 0x08
#define MCP_GPIO 0x09
#define MCP_OLAT 0x0A

#define GP0 0
#define GP1 1
#define GP2 2
#define GP3 3
#define GP4 4
#define GP5 5
#define GP6 6
#define GP7 7

// Read values from given register
// reg - register to read
// return - read value
uint8_t MCP_Register_Read(uint8_t reg);

// Read state of given pin
// pin - pin to read from (from 0 to 7)
// return - pin state (0 or 1)
uint8_t MCP_GPIO_ReadPin(uint8_t pin);

// Write value to given register
// reg - register to write to
// value - value to write
// return  - none
void MCP_Register_Write(uint8_t reg, uint8_t value);

// Set state of given pin to given state
// pin - pin to use (from 0 to 7)
// value - new state for pin (0 or 1)
// return - none
void MCP_GPIO_WritePin(uint8_t pin, uint8_t value);

#endif /* INC_MCP23S08_H_ */












