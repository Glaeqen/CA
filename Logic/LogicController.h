#pragma once

#include <stdbool.h>
#include <SDL2/SDL_stdinc.h>

typedef struct Event Event;
typedef struct LogicModel LogicModel;
typedef struct View View;
typedef struct LogicView LogicView;

typedef struct LogicController {
  Event *event;
  LogicModel *logicModel;
  LogicView *logicView;

  // State & Properties
  Uint32 lastUpdate;
  bool isManual;
  Uint32 timeBetweenSteps;
} LogicController;

void initLogicController(LogicController *logicController, Event *event, View *view);

void freeLogicController(LogicController *logicController);

void updateLogic(LogicController *logicController);

void setTimeBetweenSteps(LogicController *logicController, Uint32 timeBetweenSteps);
