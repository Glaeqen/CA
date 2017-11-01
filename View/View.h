#pragma once

#include <SDL2/SDL.h>
#include "../Logic/Logic.h"

typedef struct {
  int windowWidth;
  int windowHeight;
  SDL_Window *window;
  SDL_Renderer *renderer;

  SDL_Rect *cellsArray;
  int cellsArraySize;

  Uint8 colorsArray[2][3];
} View;

View initView(int width, int height, Logic *logic);

void freeView(View *view);

void drawLogic(View *view, Logic *logic);
