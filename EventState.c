#include "EventState.h"
#include <SDL2/SDL.h>

EventState initEventState(){
  EventState object;
  object.isRunning = 1;
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
    case SDL_KEYUP:

      break;
    }
  }
}
