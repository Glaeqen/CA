#pragma once

typedef struct Event Event;
typedef struct LogicModel LogicModel;
typedef struct LogicView LogicView;

typedef struct LogicController{
  Event *event;
  LogicModel *logicModel;
  LogicView *logicView;
} LogicController;

LogicController initLogicController();
void freeLogicController(LogicController *logicController);
