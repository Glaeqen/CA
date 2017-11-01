#pragma once

#include <SDL2/SDL.h>
#include "LogicState.h"

typedef struct {
  int windowWidth;
  int windowHeight;
  SDL_Window *window;
  SDL_Renderer *renderer;

  SDL_Rect *cellsArray;
  int cellsArraySize;

  Uint8 (*colorsArray)[3];
  int colorsArraySize;
} View;

View initView(int width, int height, LogicState *logicState);

void freeView(View *view);

void drawLogic(View *view, LogicState *logicState);
