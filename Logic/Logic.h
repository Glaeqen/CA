#pragma once

#include <SDL2/SDL.h>
#include "stdbool.h"
#include "../Event/Event.h"

typedef char State;

typedef struct {
  State *currentCAArray;
  State *previousCAArray;
  int sizeCAArray;

  Uint32 timeLastLogicUpdate;
  bool isManual;

  Uint8 amountOfStates;
} Logic;

Logic initLogic();

void freeLogic(Logic *logic);

void updateLogic(Logic *logic, Event *event);

State getStateValue(const Logic *logic, int posX, int posY);

void nextStep(Logic *logic);

int verifyConfig();
