#include "keypad.h"
#include "delay.h"

const unsigned int rows[] = {R1, R2, R3, R4};
const char keypad_seven_segments_map[] = {
        0x1, 0x2, 0x3, 0xA,
        0x4, 0x5, 0x6, 0xB,
        0x7, 0x8, 0x9, 0xC,
        0xE, 0x0, 0xF, 0xD
};

void initKeyPad() {
    SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R0 | SYSCTL_RCGCGPIO_R2;
    GPIO_PORTA_DIR_R |= (R1 | R2 | R3 | R4);
    GPIO_PORTC_DIR_R &= ~(C1 | C2 | C3 | C4);

    GPIO_PORTA_DEN_R |= (R1 | R2 | R3 | R4);
    GPIO_PORTC_DEN_R |= (C1 | C2 | C3 | C4);

    GPIO_PORTA_ODR_R |= (R1 | R2 | R3 | R4);
    GPIO_PORTC_PUR_R |= (C1 | C2 | C3 | C4);
}

char getColumnIndex(unsigned int columnBits) {
    switch (columnBits) {
        case C1:
            return 0;
        case C2:
            return 1;
        case C3:
            return 2;
        case C4:
            return 3;
        default:
            return -1;
    }
}

unsigned int getPressedColumn() {
    KEYPAD_ROWS_DATA &= ~(R1 | R2 | R3 | R4);
    delayMs(2);
    return (~KEYPAD_COLUMNS_DATA)&(C1 | C2 | C3 | C4);
}

char getPressedRowIndex(unsigned int pressedColumn) {
    for (char i = 0; i < 4; ++i) {
        KEYPAD_ROWS_DATA |= (R1 | R2 | R3 | R4);
        KEYPAD_ROWS_DATA &= ~(rows[i]);
        delayMs(2);
        if ((KEYPAD_COLUMNS_DATA&pressedColumn) == 0)
            return i;
    }
    return -1;
}

char getPressedKey() {
    unsigned int pressedColumn = getPressedColumn();
    if (!pressedColumn)
        return -1;
    char pressedRowIndex = getPressedRowIndex(pressedColumn);
    if (pressedRowIndex == -1)
        return -1;

    char pressedColumnIndex = getColumnIndex(pressedColumn);
    unsigned char keypadIndex = pressedRowIndex*4 + pressedColumnIndex;
    return keypad_seven_segments_map[keypadIndex];
}
