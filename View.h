#pragma once
#include <SDL2/SDL.h>
#include "LogicState.h"

typedef struct {
  SDL_Window *window;
  SDL_Renderer *renderer;
} View;

View initView(int width, int height);
void drawLogic(View *view, LogicState *logicState);
