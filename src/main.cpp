#include <Keypad.h>

#define MAX_NUMBER_OF_PASSWORDS = 10;
#define PASSWORD_LENGTH = 6;
#define MAXIMUM_TIME_BETWEEN_KEYS_IN_SECONDS = 3;
#define DOOR_RELAY_HIGH_OUTPUT_DURATION_IN_MILISECONDS = 50;

// Door mechanism configuration

const int doorRelayPin = 10;

// Keypad configuration

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
char keypadPasswords[MAX_NUMBER_OF_PASSWORDS][PASSWORD_LENGTH + 1] = {
  "123456",
  "234567"
};

// temporary inputted password
char keypadInput[PASSWORD_LENGTH] = {0};

// main setup

void setup () {
  Serial.begin(9600);

  // Set door relay pin to output
  pinMode(doorRelayPin, OUTPUT);
}

// Password reading

void readPasswordInput () {
  char keypadCharInput = keypad.getKey();

  if (keypadCharInput) {
    strncat(keypadInput, &keypadCharInput, 1);
  }
}

int sizeOfKeypadInput () {
  int count = 0;

  for (int i = 0; i < PASSWORD_LENGTH; i++) {
    if (keypadCharInput[i] != 0) {
      count++;
    }
  }

  return count;
}

void openDoor () {
  // Digital write to door relay.
  digitalWrite(doorRelayPin, HIGH);
  delay(DOOR_RELAY_HIGH_OUTPUT_DURATION_IN_MILISECONDS);
}

void checkPassword () {
  if (sizeOfKeypadInput() < PASSWORD_LENGTH) {
    return;
  }

  for (int i = 0; i < MAX_NUMBER_OF_PASSWORDS; i++) {
    if (strcmp(keypadInput, keypadPasswords[i]) == 0) {
      openDoor();
      break;
    }
  }
}

void loop () {
  readPasswordInput();
  checkPassword();
  maybeClearInput();
}
