#ifndef PASSWORD_KEYPAD_H
#define PASSWORD_KEYPAD_H

#define MAX_NUMBER_OF_PASSWORDS 10
#define PASSWORD_LENGTH 6

#include "Arduino.h"

const byte KEYPAD_ROWS = 4;
const byte KEYPAD_COLS = 4;

const char KEYPAD_HEXA_KEYS[KEYPAD_ROWS][KEYPAD_COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

// enum class OperationMode {
//   READ_PASSWORD,
//   ADD_PASSWORD
// };

// OperationMode operationMode = OperationMode::READ_PASSWORD;

const byte KEYPAD_ROW_PINS[KEYPAD_ROWS] = {6, 7, 8, 9};
const byte KEYPAD_COL_PINS[KEYPAD_COLS] = {2, 3, 4, 5};

const unsigned long CLEAR_PASSWORD_INPUT_INTERVAL_IN_SECONDS = 5;

const char FACTORY_PASSWORD[PASSWORD_LENGTH + 1] = "123456";

void initPasswordKeypad();
void checkPasswordKeypad(void (*openDoorCallback)());

#endif
