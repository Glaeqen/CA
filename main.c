/* Little program showcasing some cellular automaton/s. By Glaeqen. */
#include <SDL2/SDL.h>
#include <time.h>
#include "Event/Event.h"

int main(int argc, char **argv) {
  SDL_Init(SDL_INIT_VIDEO);
  srand(time(NULL));

  Event event = initEvent();
  Logic logic = initLogic();
  View view = initView(400, 400, &logic /* to comprehend */);

  while (event.isRunning) {
    handleEvents(&event);
    updateLogic(&event, &logic);
    updateView(&event, &view);
    drawLogic(&view, &logic);
  }

  freeView(&view);
  freeLogic(&logic);
  SDL_Quit();
  return 0;
}
