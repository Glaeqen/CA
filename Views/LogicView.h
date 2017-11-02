#pragma once

#include <SDL2/SDL.h>
#include "../Logic/LogicModel.h"
#include "../Controllers/CmdController.h"

typedef struct LogicView{
  SDL_Rect *cellsArray;
  int cellsArraySize;

  Uint8 colorsArray[2][3];
} LogicView;

LogicView initLogicView(LogicController logicController);

void freeView(LogicView *view);

void updateView(LogicView *view, Event *event);

void drawLogic(LogicView *view, LogicModel *logic);
