#include "EventState.h"
#include <SDL2/SDL.h>

void handleEvents(EventState *eventState){
  SDL_Event event;
  while(SDL_PollEvent(&event)){
    switch(event.type){
    case SDL_QUIT:
      eventState->isRunning = 0;
      break;
    case 
    }
  }
}
