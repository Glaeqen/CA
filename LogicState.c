#include "LogicState.h"

/* Implementation of the proper config functions goes here. */
#include "Config.h"

LogicState initLogicState(){
  LogicState object;

  object.currentCAArray = (State **)malloc(sizeof(State*)*CA_PLANAR_SIZE);
  for (int i=0; i<CA_PLANAR_SIZE; ++i) {
    object.currentCAArray[i] = (State *)malloc(sizeof(State)*CA_PLANAR_SIZE);
    for (int j=0; j<CA_PLANAR_SIZE; ++j) {
      object.currentCAArray[i][j] = 0;
    }
  }

  object.previousCAArray = (State **)malloc(sizeof(State*)*CA_PLANAR_SIZE);
  for (int i=0; i<CA_PLANAR_SIZE; ++i) {
    object.previousCAArray[i] = (State *)malloc(sizeof(State)*CA_PLANAR_SIZE);
    for (int j=0; j<CA_PLANAR_SIZE; ++j) {
      object.previousCAArray[i][j] = 0;
    }
  }

  object.timeLastLogicUpdate = SDL_GetTicks();

  object.isManual = true;

  setupStartingCAPlanar(object.currentCAArray);

  return object;
}

void freeLogicState(LogicState *logicState){
  for (int i=0; i<CA_PLANAR_SIZE; ++i) {
    free(logicState->currentCAArray[i]);
  }
  free(logicState->currentCAArray);

  for (int i=0; i<CA_PLANAR_SIZE; ++i) {
    free(logicState->previousCAArray[i]);
  }
  free(logicState->previousCAArray);
}

State getStateValue(const LogicState *logicState, int posX, int posY){
#define MOD(x, y) ((x)<0 ? ((x)%(y)+(y)) : ((x)%(y)))
  if (CA_PLANAR_EDGE_CONFIG != -1)
    if (posX<0 ||
        posX>=CA_PLANAR_SIZE ||
        posY<0 ||
        posY>=CA_PLANAR_SIZE)
      return CA_PLANAR_EDGE_CONFIG;
  return logicState->previousCAArray[MOD(posX, CA_PLANAR_SIZE)][MOD(posY, CA_PLANAR_SIZE)];
}

void nextStep(LogicState *logicState){
  for (int i=0; i<CA_PLANAR_SIZE; ++i) {
    for (int j=0; j<CA_PLANAR_SIZE; ++j) {
      logicState->previousCAArray[i][j] = logicState->currentCAArray[i][j];
    }
  }

  for (int i=0; i<CA_PLANAR_SIZE; ++i) {
    for (int j=0; j<CA_PLANAR_SIZE; ++j) {
      logicState->currentCAArray[i][j] = nextStepStateValue(logicState, i, j);
    }
  }
}

void updateLogic(LogicState *logicState, EventState *eventState){
  if (eventState->keyPressed == 'a') logicState->isManual = false;
  if (eventState->keyPressed == 'm') logicState->isManual = true;
  if (logicState->isManual) {
    if(eventState->keyPressed == 'n') {
      nextStep(logicState);
      eventState->keyPressed = 0;
    };
  }
  else {
    Uint32 currentTime = SDL_GetTicks();
    if(currentTime - logicState->timeLastLogicUpdate > CA_PLANAR_NEXT_STEP_TIME){
      nextStep(logicState);
      logicState->timeLastLogicUpdate = currentTime;
    }
  }
}

// TODO
int verifyConfig(){
  return 3;
}
