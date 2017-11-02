#include "LogicModel.h"

enum {
  /* Size of the CA planar. */
        CA_PLANAR_SIZE = 40,
  /* Time between next steps when in auto mode. */
        CA_PLANAR_NEXT_STEP_TIME = 100,
  /* Modes for planar's edges.
     -1 - Wrap around
     number != -1 -> Edge immutable state is `number` state.
  */
        CA_PLANAR_EDGE_CONFIG = -1
};

void setupStartingCAPlanar(LogicModel *logic) {
  for (int i = 0; i < (logic->sizeCAArray * logic->sizeCAArray) * 5 / 10; ++i) {
    logic->currentCAArray[(rand() % logic->sizeCAArray) * logic->sizeCAArray +
                               rand() % logic->sizeCAArray] = 1;
  }
}

State nextStepStateValue(const LogicModel *logic, int posX, int posY) {
  /* Use getStateValue() to get appropriate state */
  State currentCell = getStateValue(logic, posX, posY);
  int sum = 0;
  for (int i = -1; i < 2; ++i) {
    for (int j = -1; j < 2; ++j) {
      if (i || j)
        sum += getStateValue(logic, posX + i, posY + j);
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

LogicModel initLogic() {
  LogicModel object;

  object.currentCAArray = (State *) malloc(sizeof(State) * CA_PLANAR_SIZE * CA_PLANAR_SIZE);
  for (int i = 0; i < CA_PLANAR_SIZE; ++i) {
    for (int j = 0; j < CA_PLANAR_SIZE; ++j) {
      object.currentCAArray[CA_PLANAR_SIZE * i + j] = 0;
    }
  }

  object.previousCAArray = (State *) malloc(sizeof(State) * CA_PLANAR_SIZE * CA_PLANAR_SIZE);
  for (int i = 0; i < CA_PLANAR_SIZE; ++i) {
    for (int j = 0; j < CA_PLANAR_SIZE; ++j) {
      object.previousCAArray[CA_PLANAR_SIZE * i + j] = 0;
    }
  }

  object.sizeCAArray = CA_PLANAR_SIZE;
  object.timeLastLogicUpdate = SDL_GetTicks();
  object.isManual = true;

  object.timeBetweenSteps = CA_PLANAR_NEXT_STEP_TIME;
  object.edgeConfig = CA_PLANAR_EDGE_CONFIG;

  setupStartingCAPlanar(&object);

  return object;
}

void freeLogic(LogicModel *logic) {
  free(logic->currentCAArray);
  logic->currentCAArray = 0;

  free(logic->previousCAArray);
  logic->previousCAArray = 0;
}

void updateLogic(LogicModel *logic, Event *event) {
  if (event->keyPressed == 'a') logic->isManual = false;
  if (event->keyPressed == 'm') logic->isManual = true;
  if (logic->isManual) {
    if (event->keyPressed == 'n') {
      nextStep(logic);
      event->keyPressed = 0;
    };
  } else {
    Uint32 currentTime = SDL_GetTicks();
    if (currentTime - logic->timeLastLogicUpdate > CA_PLANAR_NEXT_STEP_TIME) {
      nextStep(logic);
      logic->timeLastLogicUpdate = currentTime;
    }
  }
}

State getStateValue(const LogicModel *logic, int posX, int posY) {
#define MOD(x, y) ((x)<0 ? ((x)%(y)+(y)) : ((x)%(y)))
  if (logic->edgeConfig != -1)
    if (posX < 0 ||
        posX >= logic->sizeCAArray ||
        posY < 0 ||
        posY >= logic->sizeCAArray)
      return logic->edgeConfig;
  return logic->previousCAArray[MOD(posX, logic->sizeCAArray) * logic->sizeCAArray +
                                MOD(posY, logic->sizeCAArray)];
}

void nextStep(LogicModel *logic) {
  for (int i = 0; i < logic->sizeCAArray; ++i) {
    for (int j = 0; j < logic->sizeCAArray; ++j) {
      logic->previousCAArray[logic->sizeCAArray * i + j] = logic->currentCAArray[
            logic->sizeCAArray * i + j];
    }
  }

  for (int i = 0; i < logic->sizeCAArray; ++i) {
    for (int j = 0; j < logic->sizeCAArray; ++j) {
      logic->currentCAArray[logic->sizeCAArray * i + j] = nextStepStateValue(logic, i, j);
    }
  }
}


// TODO
int verifyConfig() {
  return 3;
}
