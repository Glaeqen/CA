/* Little program showcasing some cellular automaton/s. By Glaeqen. */ 
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "EventState.h"
#include "LogicState.h"
#include "View.h"

int main(int argc, char **argv){
  SDL_Init(SDL_INIT_VIDEO);
  srand(time(NULL));

  EventState eventState = initEventState();
  LogicState logicState = initLogicState();
  View view = initView(900, 900, &logicState /* to comprehend */);

  while(eventState.isRunning){
    handleEvents(&eventState);
    updateLogic(&eventState, &logicState);
    updateView(&eventState, &view);
    drawLogic(&view, &logicState);
  }

  freeView(&view);
  freeLogicState(&logicState);
  SDL_Quit();
  return 0;
}
