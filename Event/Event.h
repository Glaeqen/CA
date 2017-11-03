#pragma once

typedef struct Event {
  char isRunning;
  char keyPressed;
} Event;

void initEvent(Event *event);

void handleEvents(Event *event);

void freeEvent(Event *event);