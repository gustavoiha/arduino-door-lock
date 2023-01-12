#include "Password_Keypad.h"

#define DOOR_RELAY_HIGH_OUTPUT_DURATION_IN_MILISECONDS 50;
#define DEFAULT_DELAY_IN_MILISECONDS 10;

const int doorRelayPin = 10;

void openDoor() {
  digitalWrite(doorRelayPin, HIGH);
  delay(DOOR_RELAY_HIGH_OUTPUT_DURATION_IN_MILISECONDS);
}

void setup() {
  Serial.begin(9600);
  pinMode(doorRelayPin, OUTPUT);
  initPasswordKeypad(keypad);
}

void loop() {
  readPasswordInput();
  checkPassword();
  clearPasswordInput();

  delay(DEFAULT_DELAY_IN_MILISECONDS);
}
