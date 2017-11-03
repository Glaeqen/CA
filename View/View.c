#include "View.h"

void initView(View *view, int width, int height) {
  view->window = SDL_CreateWindow("CA", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height,
                                  SDL_WINDOW_OPENGL);

  if (!view->window) {
    SDL_Log("Could not create a window.\n");
    exit(-1);
  }

  view->renderer = SDL_CreateRenderer(view->window, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);

  view->width = width;
  view->height = height;
}

void freeView(View *view) {
}
