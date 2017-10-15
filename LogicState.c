#include "LogicState.h"

/* Implementation of the proper config functions goes here. */
#include "Config.h"

LogicState initLogicState(){
  LogicState object;

  object.currentCAArray = (State *)malloc(sizeof(State)*CA_PLANAR_SIZE*CA_PLANAR_SIZE);
  for (int i=0; i<CA_PLANAR_SIZE; ++i) {
    for (int j=0; j<CA_PLANAR_SIZE; ++j) {
      object.currentCAArray[CA_PLANAR_SIZE*i + j] = 0;
    }
  }

  object.previousCAArray = (State *)malloc(sizeof(State)*CA_PLANAR_SIZE*CA_PLANAR_SIZE);
  for (int i=0; i<CA_PLANAR_SIZE; ++i) {
    for (int j=0; j<CA_PLANAR_SIZE; ++j) {
      object.previousCAArray[CA_PLANAR_SIZE*i + j] = 0;
    }
  }

  object.sizeCAArray = CA_PLANAR_SIZE;
  object.timeLastLogicUpdate = SDL_GetTicks();
  object.isManual = true;
  object.amountOfStates = 2; /* TODO From file in future */

  setupStartingCAPlanar(&object);

  return object;
}

void freeLogicState(LogicState *logicState){
  free(logicState->currentCAArray);
  logicState->currentCAArray = 0;

  free(logicState->previousCAArray);
  logicState->previousCAArray = 0;
}

State getStateValue(const LogicState *logicState, int posX, int posY){
#define MOD(x, y) ((x)<0 ? ((x)%(y)+(y)) : ((x)%(y)))
  if (CA_PLANAR_EDGE_CONFIG != -1)
    if (posX<0 ||
        posX>=logicState->sizeCAArray ||
        posY<0 ||
        posY>=logicState->sizeCAArray)
      return CA_PLANAR_EDGE_CONFIG;
  return logicState->previousCAArray[MOD(posX, logicState->sizeCAArray)*logicState->sizeCAArray + MOD(posY, logicState->sizeCAArray)];
}

void nextStep(LogicState *logicState){
  for (int i=0; i<logicState->sizeCAArray; ++i) {
    for (int j=0; j<logicState->sizeCAArray; ++j) {
      logicState->previousCAArray[logicState->sizeCAArray*i + j] = logicState->currentCAArray[logicState->sizeCAArray*i + j];
    }
  }

  for (int i=0; i<logicState->sizeCAArray; ++i) {
    for (int j=0; j<logicState->sizeCAArray; ++j) {
      logicState->currentCAArray[logicState->sizeCAArray*i + j] = nextStepStateValue(logicState, i, j);
    }
  }
}


// TODO
int verifyConfig(){
  return 3;
}
