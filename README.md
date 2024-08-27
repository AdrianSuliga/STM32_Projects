# STM32_Projects
Repository holds exercises and projects done on STM32 microcontroller

# ADC exercise
- Exercise 1: Use potentiometer to manipulate blinking frequency of 2 LEDs. 
- Exercise 2: Use value from photoresistor to manipulate brightness of 2 LEDs.
- Exercise 3: Add joystick to previous project. The board should read ADC value from this joystick and send them to PC via UART whenever user moves the stick.

# SPI on MCP23S08
- SPI_Lesson: Project contains all SPI exs from FORBOT course. The aim of those exs was to create library to interact with MCP23S08 port expander. 

# I2C and EEPROM 24AA01
- EEPROM_Lesson: Create library to handle writing and reading from EEPROM memory using I2C. Currently flashed program counts number of times when the microcontroller was booted.
- EEPROM_exs: Add two buttons to previous project. Program should keep track of how many times it was booted and how many times one of the buttons was clicked. Those values should be stored in EEPROM memory. The second button should reset those values in EEPROM memory if it is clicked when the device is booting.
