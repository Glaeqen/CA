#pragma once

#include <SDL2/SDL.h>
#include "stdbool.h"
#include "../Event/Event.h"

typedef char State;

typedef struct LogicModel {
  State *currentPlanar;
  State *previousPlanar;
  int planarSizeX;
  int planarSizeY;

  // Properties
  State edgeConfiguration;
} LogicModel;

void initLogicModel(LogicModel *logicModel);

void reInitLogicModel(LogicModel *logicModel, int xSize, int ySize, Uint8 edgeConfiguration);

void freeLogicModel(LogicModel *logicModel);

void randomizePlanar(LogicModel *logicModel, double alivePercentage);

void setStateValue(LogicModel *logicModel, int posX, int posY, State value);

State getStateValue(const LogicModel *logicModel, int posY, int posX);

static State nextStepStateValue(const LogicModel *logicModel, int posX, int posY);

static void overwriteArray(LogicModel *logicModel);

void nextStep(LogicModel *logicModel);

void setEdgeConfiguration(LogicModel *logicModel, Uint8 edgeConfiguration);

int getSizeX(LogicModel *logicModel);

int getSizeY(LogicModel *logicModel);
