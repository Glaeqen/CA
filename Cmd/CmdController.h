#pragma once

typedef struct Event Event;
typedef struct CmdModel CmdModel;
typedef struct View View;
typedef struct CmdView CmdView;
typedef struct LogicController LogicController;

typedef struct CmdController {
  LogicController *logicController;
  Event *event;
  CmdModel *cmdModel;
  CmdView *cmdView;
} CmdController;

void initCmdController(CmdController *cmdController, LogicController *logicController, Event *event, View *view);

void freeCmdController(CmdController *cmdController);