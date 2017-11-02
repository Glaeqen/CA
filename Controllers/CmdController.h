#pragma once

typedef struct Event Event;
typedef struct CmdModel CmdModel;
typedef struct CmdView CmdView;
typedef struct LogicController LogicController;

typedef struct CmdController {
  LogicController *logicController;
  Event *event;
  CmdModel *cmdModel;
  CmdView *cmdView;
} CmdController;

CmdController initCmdController(LogicController *logicController);
void freeCmdController(CmdController *cmdController);