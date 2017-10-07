#pragma once
#include <SDL2/SDL.h>
#include "EventState.h"

typedef char State;

typedef struct {
  State **currentStateArray;
} LogicState;

LogicState initLogicState();
void updateLogic(LogicState *logicState, EventState *eventState);
void drawLogic(LogicState *logicState, SDL_Renderer *renderer);
