#include <stdlib.h>
#include "LogicController.h"

LogicController initLogicController(){
  LogicController logicController;

  Event *event = malloc(sizeof(Event));
  *event = initEvent();
  logicController.event = event;

  LogicModel *logicModel = malloc(sizeof(LogicModel));
  *logicModel = initLogicModel();
  logicController.logicModel = logicModel;

  LogicView *logicView = malloc(sizeof(LogicView));
  *logicView = initLogicView(logicController);
  logicController.logicView = logicView;

  return logicController;
}

void freeLogicController(LogicController *logicController){
  freeLogicView(logicController->logicView);
  freeLogicModel(logicController->logicModel);
}
