#include "delay.h"
#include "tm4c123gh6pm.h"

void delayUs(unsigned int microseconds) {
    NVIC_ST_RELOAD_R = microseconds*1000/63;
    NVIC_ST_CTRL_R = 5;
    while ((NVIC_ST_CTRL_R & 0x10000) == 0);
    NVIC_ST_CTRL_R = 0;
}

void delayMs(unsigned int milliseconds) {
    NVIC_ST_RELOAD_R = milliseconds*1000*1000/63;
    NVIC_ST_CTRL_R = 5;
    while ((NVIC_ST_CTRL_R & 0x10000) == 0);
    NVIC_ST_CTRL_R = 0;
}
