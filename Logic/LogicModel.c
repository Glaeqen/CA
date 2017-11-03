#include "LogicModel.h"
#include "../Defaults.h"

void initLogicModel(LogicModel *logicModel) {
  reInitLogicModel(logicModel, DEFAULT_PLANAR_SIZE, DEFAULT_PLANAR_SIZE, DEFAULT_EDGE_CONFIG);
  randomizePlanar(logicModel, DEFAULT_ALIVE_PERCENTAGE / 100.);
}

void reInitLogicModel(LogicModel *logicModel, int xSize, int ySize, Uint8 edgeConfiguration) {
  logicModel->currentPlanar = (State *) malloc(sizeof(State) * xSize * ySize);
  for (int y = 0; y < ySize; ++y) {
    for (int x = 0; x < xSize; ++x) {
      logicModel->currentPlanar[xSize * y + x] = 0;
    }
  }

  logicModel->previousPlanar = (State *) malloc(sizeof(State) * xSize * ySize);
  for (int y = 0; y < ySize; ++y) {
    for (int x = 0; x < xSize; ++x) {
      logicModel->previousPlanar[xSize * y + x] = 0;
    }
  }

  logicModel->planarSizeX = xSize;
  logicModel->planarSizeY = ySize;

  logicModel->edgeConfiguration = edgeConfiguration;
}

void freeLogicModel(LogicModel *logicModel) {
  if (!logicModel) return;
  if (logicModel->currentPlanar) {
    free(logicModel->currentPlanar);
    logicModel->currentPlanar = NULL;
  }

  if (logicModel->previousPlanar) {
    free(logicModel->previousPlanar);
    logicModel->previousPlanar = NULL;
  }
}

void randomizePlanar(LogicModel *logicModel, double alivePercentage) {
  for (int i = 0; i < (logicModel->planarSizeX * logicModel->planarSizeY); ++i) {
    if (rand() / (RAND_MAX + 1.) < alivePercentage)
      logicModel->currentPlanar[(rand() % logicModel->planarSizeY) * logicModel->planarSizeX +
                                rand() % logicModel->planarSizeX] = 1;
    else
      logicModel->currentPlanar[(rand() % logicModel->planarSizeY) * logicModel->planarSizeX +
                                rand() % logicModel->planarSizeX] = 0;
  }
}

void setStateValue(LogicModel *logicModel, int posX, int posY, State value) {
  logicModel->currentPlanar[posY * logicModel->planarSizeX + posX] = value;
}

State getStateValue(const LogicModel *logicModel, int posX, int posY) {
#define MOD(x, y) ((x)<0 ? ((x)%(y)+(y)) : ((x)%(y)))
  if (logicModel->edgeConfiguration != -1)
    if (posY < 0 ||
        posY >= logicModel->planarSizeY ||
        posX < 0 ||
        posX >= logicModel->planarSizeX)
      return logicModel->edgeConfiguration;
  return logicModel->previousPlanar[MOD(posY, logicModel->planarSizeY) * logicModel->planarSizeX +
                                    MOD(posX, logicModel->planarSizeX)];
}


static State nextStepStateValue(const LogicModel *logicModel, int posX, int posY) {
  State currentCell = getStateValue(logicModel, posX, posY);
  int sum = 0;
  for (int i = -1; i < 2; ++i) {
    for (int j = -1; j < 2; ++j) {
      if (i || j)
        sum += getStateValue(logicModel, posX + i, posY + j);
    }
  }

  if (currentCell) {
    if (sum == 2 || sum == 3)
      return 1;
    else
      return 0;
  } else {
    if (sum == 3)
      return 1;
    else
      return 0;
  }
}

static void overwriteArray(LogicModel *logicModel) {
  for (int y = 0; y < logicModel->planarSizeY; ++y) {
    for (int x = 0; x < logicModel->planarSizeX; ++x) {
      logicModel->previousPlanar[logicModel->planarSizeX * y + x] = logicModel->currentPlanar[
            logicModel->planarSizeX * y + x];
    }
  }
}

void nextStep(LogicModel *logicModel) {
  overwriteArray(logicModel);
  for (int y = 0; y < logicModel->planarSizeY; ++y) {
    for (int x = 0; x < logicModel->planarSizeX; ++x) {
      logicModel->currentPlanar[logicModel->planarSizeX * y + x] = nextStepStateValue(logicModel, x, y);
    }
  }

}

void setEdgeConfiguration(LogicModel *logicModel, Uint8 edgeConfiguration) {
  logicModel->edgeConfiguration = edgeConfiguration;
}

int getSizeX(LogicModel *logicModel) {
  return logicModel->planarSizeX;
}

int getSizeY(LogicModel *logicModel) {
  return logicModel->planarSizeY;
}
