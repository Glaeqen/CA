#pragma once

#include <SDL2/SDL.h>
#include "stdbool.h"
#include "../Event/Event.h"

typedef char State;

typedef struct LogicModel{
  // Data
  State *currentCAArray;
  State *previousCAArray;
  int sizeCAArray;

  // Properties
  Uint32 timeLastLogicUpdate;
  bool isManual;

  Uint32 timeBetweenSteps;
  Uint8 edgeConfig;
} LogicModel;

LogicModel initLogic();

void freeLogic(LogicModel *logic);

void updateLogic(LogicModel *logic, Event *event);

State getStateValue(const LogicModel *logic, int posX, int posY);

void nextStep(LogicModel *logic);

int verifyConfig();
