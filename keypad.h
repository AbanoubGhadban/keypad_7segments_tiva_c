#ifndef CSE316_ASSIGNMENT2_KEYPAD_H
#define CSE316_ASSIGNMENT2_KEYPAD_H

#include "tm4c123gh6pm.h"
#include "keypad.c"
#define KEYPAD_ROWS_DATA GPIO_PORTA_DATA_R
#define KEYPAD_COLUMNS_DATA GPIO_PORTC_DATA_R

#define R1 (1U << 2)
#define R2 (1U << 3)
#define R3 (1U << 4)
#define R4 (1U << 5)

#define C1 (1U << 4)
#define C2 (1U << 5)
#define C3 (1U << 6)
#define C4 (1U << 7)

void initKeyPad();
char getPressedKey();

#endif //CSE316_ASSIGNMENT2_KEYPAD_H
