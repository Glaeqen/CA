#pragma once

#include <stdbool.h>

typedef struct Event {
  char isRunning;
  char keyPressed;
  bool windowResized;
} Event;

void initEvent(Event *event);

void handleEvents(Event *event);

void freeEvent(Event *event);
