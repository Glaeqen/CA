/* Little program showcasing some cellular automaton/s. By Glaeqen. */ 
#include <SDL2/SDL.h>
#include <stdio.h>
#include "EventState.h"
#include "LogicState.h"
#include "View.h"

int main(int argc, char **argv){
  SDL_Init(SDL_INIT_VIDEO);

  EventState eventState = initEventState();
  LogicState logicState = initLogicState();
  View view = initView(200, 200 /* to comprehend */);

  while(eventState.isRunning){
    handleEvents(&eventState);
    updateLogic(&logicState, &eventState);
    drawLogic(&view, &logicState);
  }

  freeLogicState(&logicState);
  SDL_Quit();
  return 0;
}
