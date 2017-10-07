#pragma once

typedef struct {
  char isRunning;
  char keyPressed;
} EventState;

EventState initEventState();
void handleEvents(EventState *eventState);
