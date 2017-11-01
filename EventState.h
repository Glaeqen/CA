#pragma once

#include "LogicState.h"
#include "View.h"

typedef struct {
  char isRunning;
  char keyPressed;
} EventState;

EventState initEventState();

void handleEvents(EventState *eventState);

void updateLogic(EventState *eventState, LogicState *logicState);

void updateView(EventState *eventState, View *view);
