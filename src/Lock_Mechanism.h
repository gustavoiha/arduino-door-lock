#ifndef LOCK_MECHANISM_H
#define LOCK_MECHANISM_H

#define LOCK_OUTPUT_RELAY_PIN 10;
#define LOCK_RELAY_HIGH_OUTPUT_DURATION_IN_MILISECONDS 50;
#define LOCK_COOL_DOWN_IN_MILISECONDS 500;

void initDoorLock();
void openDoorLock();

#endif
