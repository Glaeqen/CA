#pragma once

typedef struct EventState{
  int isRunning;

} EventState;

EventState initEventState();
void handleEvents(EventState *eventState);
