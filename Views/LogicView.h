#pragma once

#include <SDL2/SDL.h>

typedef struct LogicController LogicController;
typedef struct View View;

typedef struct LogicView{
  LogicController *logicController;
  View *view;

  SDL_Rect *cellsArray;
  int cellsArraySizeX;
  int cellsArraySizeY;

  Uint8 colorsArray[2][3];
} LogicView;

void initLogicView(LogicView *logicView, LogicController *logicController, View *view);

void freeLogicView(LogicView *logicView);

void drawLogicView(LogicView *logicView);
