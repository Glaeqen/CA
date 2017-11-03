#pragma once

#include "Controllers/CmdController.h"
#include "Controllers/LogicController.h"

typedef struct Application{
  View *view;
  Event *event;
  LogicController *logicController;
//  CmdController *cmdController;
} Application;

static void initApplication(Application *application);
static void mainLoop(Application *application);
static void freeApplication(Application *application);
