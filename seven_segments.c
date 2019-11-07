#include "seven_segments.h"

const unsigned char ss_map[16] = {
        0x3F, 0x06, 0x5B, 0x4F,
        0x66, 0x6D, 0x7D, 0x07,
        0x7F, 0x6F, 0x77, 0x7C,
        0x39, 0x5E, 0x79, 0x71
    };

void sevenSegmentsInit() {
    SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R1;
    GPIO_PORTB_DIR_R |= 0x7F;
    GPIO_PORTB_DEN_R |= 0x7F;
}

void turnOffSevenSegments() {
    SEVEN_SEGMENTS_DATA |= 0x7F;
}

void outputDigit(unsigned char digit) {
    SEVEN_SEGMENTS_DATA &= ~(ss_map[digit]);
    SEVEN_SEGMENTS_DATA |= ~(ss_map[digit]);
}
