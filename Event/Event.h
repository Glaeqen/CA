#pragma once

typedef struct Event{
  char isRunning;
  char keyPressed;
} Event;

Event initEvent();

void handleEvents(Event *event);
