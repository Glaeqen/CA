#pragma once
#include <SDL2/SDL.h>
#include "EventState.h"
#include "stdbool.h"

typedef char State;

typedef struct {
  State **currentCAArray;
  State **previousCAArray;
  Uint32 timeLastLogicUpdate;
  bool isManual;
} LogicState;

void setupStartingCAPlanar(State **planar);
State nextStepStateValue(const LogicState *logicState, int posX, int posY);

LogicState initLogicState();
void freeLogicState(LogicState *logicState);

State getStateValue(const LogicState *logicState, int posX, int posY);
void nextStep(LogicState* logicState);

void updateLogic(LogicState *logicState, EventState *eventState);

int verifyConfig();
