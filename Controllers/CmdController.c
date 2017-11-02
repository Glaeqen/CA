#include <stdlib.h>
#include "CmdController.h"
#include "LogicController.h"

CmdController initCmdController(LogicController* logicController){
  CmdController cmdController;
  cmdController.logicController = logicController;

  cmdController.event = logicController->event;

  CmdModel *cmdModel = malloc(sizeof(cmdModel));
  *cmdModel = initCmdModel();
  cmdController.cmdModel = cmdModel;

  CmdView *cmdView = malloc(sizeof(cmdView));
  *cmdView = initCmdView(cmdController);
  cmdController.cmdView = cmdView;

  return cmdController;
}

void freeCmdController(CmdController *cmdController){
  freeCmdModel(cmdController->cmdModel);
  freeCmdView(cmdController->cmdView);
}
