#pragma once

typedef struct EventState{
  int isRunning = 1;

} EventState;

void handleEvents(EventState *eventState);
