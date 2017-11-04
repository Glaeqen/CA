#include <stdlib.h>
#include "CmdController.h"
#include "../Logic/LogicController.h"

void initCmdController(CmdController *cmdController, LogicController *logicController, Event *event, View *view) {
  cmdController->logicController = logicController;

  cmdController->event = event;

  CmdModel *cmdModel = malloc(sizeof(cmdModel));
  initCmdModel(cmdModel);
  cmdController->cmdModel = cmdModel;

  CmdView *cmdView = malloc(sizeof(cmdView));
  initCmdView(cmdView, cmdController, view);
  cmdController->cmdView = cmdView;
}

void freeCmdController(CmdController *cmdController) {
  if (cmdController->cmdModel) {
    freeCmdModel(cmdController->cmdModel);
    free(cmdController->cmdModel);
    cmdController->cmdModel = NULL;
  }

  if (cmdController->cmdView) {
    freeCmdView(cmdController->cmdView);
    free(cmdController->cmdView);
    cmdController->cmdView = NULL;
  }
}
