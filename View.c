#include "View.h"

View initView(int width, int height) {
  View object;
  object.window = SDL_CreateWindow("CA", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_OPENGL);

  if(!object.window){
    fprintf(stderr, "Could not create a window.\n");
    exit(-1);
  }

  object.renderer = SDL_CreateRenderer(object.window, -1, SDL_RENDERER_PRESENTVSYNC);
  return object;
}

void drawLogic(View *view, LogicState *logicState){
  /* TODO */
  /* SDL_SetRenderDrawColor(view->renderer, 0, 0, 255, 255); */
  /* SDL_RenderClear(view->renderer); */
  /* SDL_RenderPresent(view->renderer); */
}



