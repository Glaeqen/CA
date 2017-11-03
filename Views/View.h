#pragma once

#include <SDL2/SDL.h>

typedef struct View{
  SDL_Window *window;
  SDL_Renderer *renderer;
  int width;
  int height;
} View;

void initView(View *view, int width, int height);

void freeView(View *view);
