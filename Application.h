#pragma once

#include "Controllers/CmdController.h"
#include "Controllers/LogicController.h"

typedef struct Application{
  LogicController *logicController;
  CmdController *cmdController;
} Application;

static Application initApplication();
static void mainLoop(Application *application);
static void freeApplication(Application *application);
