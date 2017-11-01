#include "Logic.h"

/* Implementation of the proper config functions goes here. */
#include "../Config.h"

Logic initLogic() {
  Logic object;

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
  object.amountOfStates = 2; /* TODO From file in future */

  setupStartingCAPlanar(&object);

  return object;
}

void freeLogic(Logic *logic) {
  free(logic->currentCAArray);
  logic->currentCAArray = 0;

  free(logic->previousCAArray);
  logic->previousCAArray = 0;
}

State getStateValue(const Logic *logic, int posX, int posY) {
#define MOD(x, y) ((x)<0 ? ((x)%(y)+(y)) : ((x)%(y)))
  if (CA_PLANAR_EDGE_CONFIG != -1)
    if (posX < 0 ||
        posX >= logic->sizeCAArray ||
        posY < 0 ||
        posY >= logic->sizeCAArray)
      return CA_PLANAR_EDGE_CONFIG;
  return logic->previousCAArray[MOD(posX, logic->sizeCAArray) * logic->sizeCAArray +
                                     MOD(posY, logic->sizeCAArray)];
}

void nextStep(Logic *logic) {
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
