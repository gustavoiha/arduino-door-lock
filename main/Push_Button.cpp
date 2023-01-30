#include "Arduino.h"
#include "Push_Button.h"

void initPushButton() {
  pinMode(PUSH_BUTTON_INPUT_PIN, INPUT);
}

void checkPushButton(void (*callbackOpenDoor)()) {
  if (digitalRead(PUSH_BUTTON_INPUT_PIN) == HIGH) {
    callbackOpenDoor();
  }
}
