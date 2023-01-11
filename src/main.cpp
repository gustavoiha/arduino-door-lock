#include <Keypad.h>

#define NUMBER_OF_PASSWORDS = 10;
#define PASSWORD_LENGTH = 6;
#define MAXIMUM_TIME_BETWEEN_KEYS_IN_SECONDS = 3;

// Keypad variables

// amount of keypad rows and columns
const byte KEYPAD_ROWS = 4;
const byte KEYPAD_COLS = 4;

char keypadHexaKeys[KEYPAD_ROWS][KEYPAD_COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

// digital pins connecting the rows and columns of the keypad
const byte keypadRowPins[KEYPAD_ROWS] = {9, 8, 7, 6};
const byte keypadColPins[KEYPAD_COLS] = {5, 4, 3, 2};

// initialize an instance of class Keypad
keymap = makeKeymap(keypadHexaKeys);
Keypad keypad = Keypad(keymap, keypadRowPins, keypadColPins, KEYPAD_ROWS, KEYPAD_COLS);

// allowed passwords
char keypadPasswords[2][7] = {
  "123456",
  "234567"
};

// temporarilly stored inputted password
char keypadInput[PASSWORD_LENGTH] = {0};

// main setup and loop

void setup () {
  Serial.begin(9600);
}

void loop () {
  char keypadCharInput = keypad.getKey();

  if (keypadCharInput) {
    strncat(keypadInput, &keypadCharInput, 1);
  }

  for (int i = 0; i < 2; i++) {
    if (strcmp(keypadInput, keypadPasswords[i]) == 0) {
      // matched password
    }
  }
}
