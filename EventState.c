#include "EventState.h"
#include <SDL2/SDL.h>

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
