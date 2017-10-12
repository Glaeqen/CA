#include "EventState.h"
#include <SDL2/SDL.h>

/* Implementation of the proper config functions goes here. */
#include "Config.h"

EventState initEventState(){
  EventState object;
  object.isRunning = 1;
  object.keyPressed = 0;
  return object;
}

void handleEvents(EventState *eventState){
  SDL_Event event;
  while(SDL_PollEvent(&event)){
    switch(event.type){
    case SDL_QUIT:
      eventState->isRunning = 0;
      break;
    case SDL_KEYDOWN:
      eventState->keyPressed = event.key.keysym.sym;
      break;
    case SDL_KEYUP:
      eventState->keyPressed = 0;
      break;
    }
  }
}

void updateLogic(EventState *eventState, LogicState *logicState){
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

void updateView(EventState* eventState, View* view) {
}
