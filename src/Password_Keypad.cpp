#include "Password_Keypad.h"
#include <Keypad.h>

Keypad keypad;

char keypadPasswords[MAX_NUMBER_OF_PASSWORDS][PASSWORD_LENGTH + 1] = {
  "123456",
  "234567"
};

char keypadInput[PASSWORD_LENGTH] = {0};
int keypadInputIndex = 0;

unsigned long lastKeypadInputTime = 0;

void initPasswordKeypad() {
  keypad = Keypad(makeKeymap(KEYPAD_HEXA_KEYS), KEYPAD_ROW_PINS, KEYPAD_COL_PINS, KEYPAD_ROWS, KEYPAD_COLS);
}

void storeLastKeypadInputTime() {
  lastKeypadInputTime = millis();
}

void readPasswordInput() {
  char input = keypad.getKey();
  if (input) {
    keypadInput[keypadInputIndex++] = input;
    storeLastKeypadInputTime();
  }
}

int sizeOfKeypadInput() {
  int count = 0;

  for (int i = 0; i < PASSWORD_LENGTH; i++) {
    if (keypadInput[i] != 0) {
      count++;
    }
  }

  return count;
}

bool passwordMatches(char input[], char password[]) {
  for (int i = 0; i < PASSWORD_LENGTH; i++) {
    if (input[i] == password[i]) {
      return true;
    }
  }
  return false;
}

void checkPassword(void (*openDoorCallback)()) {
  if (sizeOfKeypadInput() < PASSWORD_LENGTH) {
    return;
  }

  for (int i = 0; i < MAX_NUMBER_OF_PASSWORDS; i++) {
    if (passwordMatches(keypadInput, keypadPasswords[i])) {
      openDoorCallback();
      break;
    }
  }
}

void clearPasswordInput() {
  unsigned long currentTime = millis();

  if (currentTime - lastKeypadInputTime >= CLEAR_PASSWORD_INPUT_INTERVAL_IN_SECONDS) {
    lastKeypadInputTime = currentTime;
    keypadInputIndex = 0;
    memset(keypadInput, '\0', PASSWORD_LENGTH);
  }
}
