#include "seven_segments.h"
#include "seven_segments.c"
#include "keypad.h"
#include "keypad.c"

int main() {
  sevenSegmentsInit();
  initKeyPad();

  while (1) {
      char pressedKey = getPressedKey();
      if (pressedKey == -1)
        turnOffSevenSegments();
      else
        outputDigit(pressedKey);
  }
}
