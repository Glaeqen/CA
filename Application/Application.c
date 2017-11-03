#include "Application.h"
#include "../View/View.h"
#include "../Defaults.h"
#include "../Event/Event.h"
#include <time.h>

void initApplication(Application *application) {
  SDL_Init(SDL_INIT_VIDEO);
  srand(time(NULL));
  View *view = malloc(sizeof(View));
  initView(view, DEFAULT_WINDOW_SIZE_XY, DEFAULT_WINDOW_SIZE_XY);
  application->view = view;

  Event *event = malloc(sizeof(Event));
  initEvent(event);
  application->event = event;

  LogicController *logicController = malloc(sizeof(LogicController));
  initLogicController(logicController, event, view);
  application->logicController = logicController;

//  CmdController *cmdController = malloc(sizeof(CmdController));
//  *cmdController = initCmdController(logicController, event, view);
//  application->cmdController = cmdController;
}

void mainLoop(Application *application) {
  while (application->event->isRunning) {
    handleEvents(application->event);
    updateLogic(application->logicController);
//    updateCmd(application->cmdController);
  }
}

void freeApplication(Application *application) {
  if (!application) return;
//  freeCmdController(application->cmdController);
  freeLogicController(application->logicController);
  freeView(application->view);
  freeEvent(application->event);
  SDL_Quit();
}

int main() {
  Application application;
  initApplication(&application);
  mainLoop(&application);
  freeApplication(&application);
}
