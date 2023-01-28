#include "Lock_Mechanism.h"

unsigned long lastTimeLockOpened = 0;

void initDoorLock() {
  pinMode(LOCK_OUTPUT_RELAY_PIN, OUTPUT);
}

void openDoorLock() {
  unsigned long currentTime = millis();

  if (currentTime - lastTimeLockOpened >= LOCK_COOL_DOWN_IN_MILISECONDS) {
    lastTimeLockOpened = currentTime;
    digitalWrite(LOCK_OUTPUT_RELAY_PIN, HIGH);
    delay(LOCK_RELAY_HIGH_OUTPUT_DURATION_IN_MILISECONDS);
  }
}
