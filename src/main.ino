#include "Lock_Mechanism.h"
#include "Password_Keypad.h"
#include "Push_Button.h"

#define DEFAULT_SYSTEM_DELAY_IN_MILISECONDS 100;

void setup() {
  Serial.begin(9600);
  initDoorLock();
  initPasswordKeypad();
  initPushButton();
}

void loop() {
  // Open door lock via keypad password
  readPasswordInput();
  checkPassword(&openDoorLock);
  clearPasswordInput();

  // Open door lock via push button
  checkPushButton(&openDoorLock);

  delay(DEFAULT_SYSTEM_DELAY_IN_MILISECONDS);
}
