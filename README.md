# STM32_Projects
Repository holds exercises and projects done on STM32 microcontroller

# ADC exercise
- Exercise 1: Use potentiometer to manipulate blinking frequency of 2 LEDs. 
- Exercise 2: Use value from photoresistor to manipulate brightness of 2 LEDs.
- Exercise 3: Add joystick to previous project. The board should read ADC value from this joystick and send them to PC via UART whenever user moves the stick.

# SPI on MCP23S08
- SPI_Lesson: Project contains all SPI exs from FORBOT course. The aim of those exs was to create library to interact with MCP23S08 port expander. 

# I2C on EEPROM 24AA01
- EEPROM_Lesson: Create library to handle writing and reading from EEPROM memory using I2C. Currently flashed program counts number of times when the microcontroller was booted.
- EEPROM_exs: Add two buttons to previous project. Program should keep track of how many times it was booted and how many times one of the buttons was clicked. Those values should be stored in EEPROM memory. The second button should reset those values in EEPROM memory if it is clicked when the device is booting.

# I2C on LPS25HB
- I2C_LPS25HB_lesson: Create library to handle reading pressure and temperature from LPS25HB sensor. Program uses those value to calculate height relative to place where the device was booted.
- I2C_LPS25HB_exs: Expand library with function that measures ratio between reference pressure and current pressure. Reference pressure should be measured once and stored in REF_P register. Main program should use this to measure sensor's height relative to its position when it was first booted. This height than should be used to smoothly change RGB diode color, if the relative height is negative - set it to blue, if it is positive - set it to red. The bigger the absolute value of relative height, the brighter the diode should be

# HCSR04 and 7-segment display
- HCSR04_lesson: Create library to handle displaying numbers on 7-segment display. The display shows distance from the obstacle measured by HC-SR04 sensor. This distance is also used to smoothly control RGB diode, green value indicates that obstacle is far away while red that it is close. Everything descrived above is implemented using interrupts which allows main while loop to remain empty.
