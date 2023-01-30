#include "Password_Keypad.h"
#include <Keypad.h>

Keypad keypad = Keypad(
  makeKeymap(KEYPAD_HEXA_KEYS),
  KEYPAD_ROW_PINS,
  KEYPAD_COL_PINS,
  KEYPAD_ROWS,
  KEYPAD_COLS
);

char passwords[5][10];
int passwordsCount = 0;
char keypadInput[7];
int keypadInputIndex = 0;

unsigned long lastKeypadInputTime = 0;

void enableFactoryPassword() {
  strcpy(passwords[passwordsCount++], FACTORY_PASSWORD);
}

void initPasswordKeypad() {
  enableFactoryPassword();
}

void addInputToPasswords() {
  strcpy(passwords[passwordsCount++], keypadInput);
}

void storeLastKeypadInputTime() {
  lastKeypadInputTime = millis();
}

void readKeypadInput() {
  char input = keypad.getKey();

  if (input) {
    Serial.print("Keypad input: ");
    Serial.println(input);

    keypadInput[keypadInputIndex++] = input;
    storeLastKeypadInputTime();
  }
}

bool keypadInputMatchesPassword() {
  for (int i = 0; i < passwordsCount; i++) {
    if (strcmp(passwords[i], keypadInput) == 0) {
      return true;
    }
  }

  return false;
}

void clearOldKeypadInput() {
  unsigned long currentTime = millis();

  if (currentTime - lastKeypadInputTime >= CLEAR_PASSWORD_INPUT_INTERVAL_IN_SECONDS) {
    lastKeypadInputTime = currentTime;
    keypadInputIndex = 0;
    memset(keypadInput, 0, sizeof(keypadInput));
  }
}

void checkPasswordKeypad(void (*openDoorCallback)()) {
  clearOldKeypadInput();
  readKeypadInput();

  if (keypadInputIndex < PASSWORD_LENGTH) {
    return;
  }

  // switch (operationMode) {
    // case OperationMode::READ_PASSWORD:
      if (keypadInputMatchesPassword()) {
        openDoorCallback();
      }
  //     break;
  //   case OperationMode::ADD_PASSWORD:
  //     addInputToPasswords();
  //     break;
  // }
}
