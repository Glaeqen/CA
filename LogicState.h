#pragma once

#include <SDL2/SDL.h>
#include "stdbool.h"

typedef char State;

typedef struct {
  State *currentCAArray;
  State *previousCAArray;
  int sizeCAArray;

  Uint32 timeLastLogicUpdate;
  bool isManual;

  Uint8 amountOfStates;
} LogicState;

LogicState initLogicState();

void freeLogicState(LogicState *logicState);

State getStateValue(const LogicState *logicState, int posX, int posY);

void nextStep(LogicState *logicState);

int verifyConfig();
