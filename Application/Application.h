#pragma once

#include "../Cmd/CmdController.h"
#include "../Logic/LogicController.h"

typedef struct Application {
  View *view;
  Event *event;
  LogicController *logicController;
//  CmdController *cmdController;
} Application;

void initApplication(Application *application);

void mainLoop(Application *application);

void freeApplication(Application *application);
