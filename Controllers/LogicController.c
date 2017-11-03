#include <stdlib.h>
#include "../Defaults.h"
#include "LogicController.h"
#include "../Models/LogicModel.h"
#include "../Views/LogicView.h"

void initLogicController(LogicController *logicController, Event *event, View *view) {
  logicController->event = event;

  LogicModel *logicModel = malloc(sizeof(LogicModel));
  initLogicModel(logicModel);
  logicController->logicModel = logicModel;

  LogicView *logicView = malloc(sizeof(LogicView));
  initLogicView(logicView, logicController, view);
  logicController->logicView = logicView;

  logicController->lastUpdate = SDL_GetTicks();
  logicController->isManual = DEFAULT_IS_MANUAL_BOOLEAN;
  logicController->timeBetweenSteps = DEFAULT_NEXT_STEP_TIME;
}

void freeLogicController(LogicController *logicController) {
  if (!logicController) return;
  freeLogicView(logicController->logicView);
  logicController->logicView = NULL;
  freeLogicModel(logicController->logicModel);
  logicController->logicModel = NULL;
}

void updateLogicController(LogicController *logicController) {
  if (logicController->event->keyPressed == 'a') logicController->isManual = false;
  if (logicController->event->keyPressed == 'm') logicController->isManual = true;
}

void updateLogicModel(LogicController *logicController) {
  // Manual control
  if (logicController->isManual) {
    if (logicController->event->keyPressed == 'n') {
      nextStep(logicController->logicModel);
      logicController->event->keyPressed = 0;
    };
  }
    // Automatic control
  else {
    Uint32 currentTime = SDL_GetTicks();
    if (currentTime - logicController->lastUpdate > logicController->timeBetweenSteps) {
      nextStep(logicController->logicModel);
      logicController->lastUpdate = currentTime;
    }
  }
}

void updateLogicView(LogicController *logicController) {
  drawLogicView(logicController->logicView);
}

void updateLogic(LogicController *logicController) {
  updateLogicController(logicController);
  updateLogicModel(logicController);
  updateLogicView(logicController);
}

void setTimeBetweenSteps(LogicController *logicController, Uint32 timeBetweenSteps){
  logicController->timeBetweenSteps = timeBetweenSteps;
}
