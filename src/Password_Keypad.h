#ifndef PASSWORD_KEYPAD_H
#define PASSWORD_KEYPAD_H

#define MAX_NUMBER_OF_PASSWORDS 10
#define PASSWORD_LENGTH 6

#define KEYPAD_ROWS 4
#define KEYPAD_COLS 4

const char keypadHexaKeys[KEYPAD_ROWS][KEYPAD_COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

const byte keypadRowPins[KEYPAD_ROWS] = {9, 8, 7, 6};
const byte keypadColPins[KEYPAD_COLS] = {5, 4, 3, 2};

const unsigned long CLEAR_PASSWORD_INPUT_INTERVAL_IN_SECONDS = 3;

void readPasswordInput();
void checkPassword();
void clearPasswordInput();

#endif
