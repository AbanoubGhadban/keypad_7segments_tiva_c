#ifndef CSE316_ASSIGNMENT2_SEVEN_SEGMENTS_H
#define CSE316_ASSIGNMENT2_SEVEN_SEGMENTS_H

#include "tm4c123gh6pm.h"

#define SEVEN_SEGMENTS_DATA GPIO_PORTB_DATA_R

void sevenSegmentsInit();
void turnOffSevenSegments();
void outputDigit(unsigned char digit);

#endif //CSE316_ASSIGNMENT2_SEVEN_SEGMENTS_H
