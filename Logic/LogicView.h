#pragma once

#include <SDL2/SDL.h>

typedef struct LogicController LogicController;
typedef struct ViewHolder ViewHolder;

typedef struct LogicView {
  LogicController *logicController;
  ViewHolder *viewHolder;

  SDL_Rect *cellsArray;
  int cellsArraySizeX;
  int cellsArraySizeY;

  Uint8 colorsArray[2][3];
} LogicView;

void initLogicView(LogicView *logicView, LogicController *logicController, ViewHolder *viewHolder);

void freeLogicView(LogicView *logicView);

void drawLogicView(LogicView *logicView);

void reInitLogicView(LogicView *logicView);
