#include "seven_segments.h"
#include "keypad.h"

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
