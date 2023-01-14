#ifndef PUSH_BUTTON_H
#define PUSH_BUTTON_H

#define PUSH_BUTTON_INPUT_PIN 1;

void initPushButton();
void checkPushButton(void (*openDoorCallback)());

#endif
