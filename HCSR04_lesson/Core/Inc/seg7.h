/*
 * seg7.h
 *
 *  Created on: Aug 31, 2024
 *      Author: arima
 */

#ifndef INC_SEG7_H_
#define INC_SEG7_H_

#include <stdint.h>

// Show digit on the screen
// value - digit to show
void SEG7_Show_Digit(uint32_t value);

// Show 2-digit number
// value - digit to show
void SEG7_Show(uint32_t value);

// Change current active screen
void SEG7_Update(void);

#endif /* INC_SEG7_H_ */
