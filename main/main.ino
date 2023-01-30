#include "Lock_Mechanism.h"
#include "Password_Keypad.h"
#include "Push_Button.h"

#define DEFAULT_SYSTEM_DELAY_IN_MILISECONDS 50

void setup() {
  Serial.begin(9600);

  Serial.print("Arduino Door Lock starting!");
  initDoorLock();
  initPasswordKeypad();
  initPushButton();
}

void loop() {
  // Open door lock via keypad password
  checkPasswordKeypad(&openDoorLock);

  // Open door lock via push button
  checkPushButton(&openDoorLock);

  delay(DEFAULT_SYSTEM_DELAY_IN_MILISECONDS);
}
