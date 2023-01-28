#include "Password_Keypad.h"
#include <Keypad.h>

#include <vector>
#include <string>

Keypad keypad;

std::vector<std::string> passwords;
std::string keypadInput;

unsigned long lastKeypadInputTime = 0;

void initPasswordKeypad() {
  enableFactoryPassword();

  keypad = Keypad(
    makeKeymap(KEYPAD_HEXA_KEYS),
    KEYPAD_ROW_PINS,
    KEYPAD_COL_PINS,
    KEYPAD_ROWS,
    KEYPAD_COLS
  );
}

void enableFactoryPassword() {
  passwords.push_back(FACTORY_PASSWORD);
}

void checkPasswordKeypad(void (*openDoorCallback)()) {
  clearOldKeypadInput();
  readKeypadInput();

  if (keypadInput.length() < PASSWORD_LENGTH) {
    return;
  }

  switch (operationMode) {
    case OperationMode::READ_PASSWORD:
      if (keypadInputMatchesPassword()) {
        openDoorCallback();
      }
      break;
    case OperationMode::ADD_PASSWORD:
      addInputToPasswords();
      break;
  }
}

void addInputToPasswords() {
  passwords.push_back(keypadInput);
}

void storeLastKeypadInputTime() {
  lastKeypadInputTime = millis();
}

void readKeypadInput() {
  char input = keypad.getKey();

  if (input) {
    keypadInput.push_back(input);
    storeLastKeypadInputTime();
  }
}

bool keypadInputMatchesPassword() {
  for (const auto & password : passwords) {
    if (password == keypadInput) {
      return true;
    }
  }

  return false;
}

void clearOldKeypadInput() {
  unsigned long currentTime = millis();

  if (currentTime - lastKeypadInputTime >= CLEAR_PASSWORD_INPUT_INTERVAL_IN_SECONDS) {
    lastKeypadInputTime = currentTime;
    keypadInput.clear();
  }
}
