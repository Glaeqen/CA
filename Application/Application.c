#include "Application.h"
#include "../Defaults.h"
#include "../Event/Event.h"
#include "../ViewHolder/ViewHolder.h"
#include <time.h>

void initApplication(Application *application) {
  SDL_Init(SDL_INIT_VIDEO);
  srand(time(NULL));
  ViewHolder *viewHolder = malloc(sizeof(ViewHolder));
  initViewHolder(viewHolder, DEFAULT_WINDOW_SIZE_XY, DEFAULT_WINDOW_SIZE_XY);
  application->viewHolder = viewHolder;

  Event *event = malloc(sizeof(Event));
  initEvent(event);
  application->event = event;

  LogicController *logicController = malloc(sizeof(LogicController));
  initLogicController(logicController, event, viewHolder);
  application->logicController = logicController;

//  CmdController *cmdController = malloc(sizeof(CmdController));
//  initCmdController(cmdController, logicController, event, viewHolder);
//  application->cmdController = cmdController;
}

void mainLoop(Application *application) {
  while (application->event->isRunning) {
    handleEvents(application->event);
    clearScreenViewHolder(application->viewHolder);
    updateLogic(application->logicController);
//    updateCmd(application->cmdController);
  }
}

void freeApplication(Application *application) {
//  if(application->cmdController) {
//  freeCmdController(application->cmdController);
//    free(application->cmdController);
//    application->cmdController = NULL;
//  }

  if (application->logicController) {
    freeLogicController(application->logicController);
    free(application->logicController);
    application->logicController = NULL;
  }

  if (application->viewHolder) {
    freeViewHolder(application->viewHolder);
    free(application->viewHolder);
    application->viewHolder = NULL;
  }
  SDL_Quit();
}

int main() {
  Application application;
  initApplication(&application);
  mainLoop(&application);
  freeApplication(&application);
}
