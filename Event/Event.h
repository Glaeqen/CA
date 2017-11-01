#pragma once

#include "../Logic/Logic.h"
#include "../View/View.h"

typedef struct {
  char isRunning;
  char keyPressed;
} Event;

Event initEvent();

void handleEvents(Event *event);

void updateLogic(Event *event, Logic *logic);

void updateView(Event *event, View *view);
