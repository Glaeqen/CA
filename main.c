/* Little program showcasing some cellular automaton/s. By Glaeqen. */ 
#include <SDL2/SDL.h>
#include "EventState.h"
#include "LogicState.h"
#include <stdio.h>

int main(){
  SDL_Window *window = NULL;
  SDL_Renderer *renderer = NULL;

  SDL_Init(SDL_INIT_VIDEO);
  window = SDL_CreateWindow("CA", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 200, 200, SDL_WINDOW_OPENGL);

  if(!window){
    fprintf(stderr, "Could not create a window.\n");
    return -1;
  }

  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

  SDL_Event event;
  EventState eventState;
  LogicState logicState;

  while(eventState.isRunning){
    handleEvents(&eventState);
    updateLogic(&logicState, &eventState);
    drawLogic(&logicState, renderer);
  }

  SDL_Quit();
  return 0;
}
