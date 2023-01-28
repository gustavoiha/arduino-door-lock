#ifndef PASSWORD_KEYPAD_H
#define PASSWORD_KEYPAD_H

#define MAX_NUMBER_OF_PASSWORDS 10
#define PASSWORD_LENGTH 6

#define KEYPAD_ROWS 4
#define KEYPAD_COLS 4

const char KEYPAD_HEXA_KEYS[KEYPAD_ROWS][KEYPAD_COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

const char PASSWORD_KEYS[10] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};

enum class OperationMode = {
  READ_PASSWORD,
  ADD_PASSWORD
}

OperationMode operationMode = OperationMode::READ_PASSWORD;

const byte KEYPAD_ROW_PINS[KEYPAD_ROWS] = {9, 8, 7, 6};
const byte KEYPAD_COL_PINS[KEYPAD_COLS] = {5, 4, 3, 2};

const unsigned long CLEAR_PASSWORD_INPUT_INTERVAL_IN_SECONDS = 5;

const char FACTORY_PASSWORD[PASSWORD_LENGTH + 1] = "123456";

void initPasswordKeypad();
void checkPasswordKeypad(void (*openDoorCallback)());

#endif
