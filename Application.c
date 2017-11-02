#include "Application.h"
#include <SDL2/SDL.h>
#include <time.h>

Application initApplication(){
  Application application;

  LogicController *logicController = malloc(sizeof(LogicController));
  *logicController = initLogicController();
  application.logicController = logicController;

  CmdController *cmdController = malloc(sizeof(CmdController));
  *cmdController = initCmdController(logicController);
  application.cmdController = cmdController;

  return application;
}

void mainLoop(Application *application){
  SDL_Init(SDL_INIT_VIDEO);
  srand(time(NULL));

  Event event = initEvent();
  LogicModel logic = initLogic();
  LogicView view = initView(400, 400, &logic /* to comprehend */);

  while (event.isRunning) {
    handleEvents(&event);
    updateLogic(&logic, &event);
    updateView(&view, &event);
    drawLogic(&view, &logic);
  }

  freeView(&view);
  freeLogic(&logic);
  SDL_Quit();
}

int main(){
  Application application = initApplication();
  mainLoop(&application);
}

void freeApplication(Application *application){
  freeCmdController(application->cmdController);
  freeLogicController(application->logicController);
}
