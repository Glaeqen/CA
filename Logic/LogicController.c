#include <stdlib.h>
#include "../Defaults.h"
#include "LogicController.h"
#include "LogicModel.h"
#include "LogicView.h"
#include "../ViewHolder/ViewHolder.h"

void initLogicController(LogicController *logicController, Event *event, ViewHolder *viewHolder) {
  logicController->event = event;

  LogicModel *logicModel = malloc(sizeof(LogicModel));
  initLogicModel(logicModel);
  logicController->logicModel = logicModel;

  LogicView *logicView = malloc(sizeof(LogicView));
  initLogicView(logicView, logicController, viewHolder);
  logicController->logicView = logicView;

  logicController->lastUpdate = SDL_GetTicks();
  logicController->isManual = DEFAULT_IS_MANUAL_BOOLEAN;
  logicController->timeBetweenSteps = DEFAULT_NEXT_STEP_TIME;
}

void freeLogicController(LogicController *logicController) {
  if (logicController->logicView) {
    freeLogicView(logicController->logicView);
    free(logicController->logicView);
    logicController->logicView = NULL;
  }

  if (logicController->logicModel) {
    freeLogicModel(logicController->logicModel);
    free(logicController->logicModel);
    logicController->logicModel = NULL;
  }
}

static void updateLogicController(LogicController *logicController) {
  if (logicController->event->keyPressed == 'a') logicController->isManual = false;
  if (logicController->event->keyPressed == 'm') logicController->isManual = true;
}

static void updateLogicModel(LogicController *logicController) {
  // Manual control
  if (logicController->isManual) {
    if (logicController->event->keyPressed == 'n') {
      nextStep(logicController->logicModel);
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

static void updateLogicView(LogicController *logicController) {
  if (logicController->event->windowResized) reInitLogicView(logicController->logicView);
  if (logicController->event->keyPressed == 'r'){
    SDL_SetWindowSize(logicController->logicView->viewHolder->window, DEFAULT_WINDOW_SIZE_XY, DEFAULT_WINDOW_SIZE_XY);
    reInitLogicView(logicController->logicView);
  }
  drawLogicView(logicController->logicView);
}

void updateLogic(LogicController *logicController) {
  updateLogicController(logicController);
  updateLogicModel(logicController);
  updateLogicView(logicController);
}

void setTimeBetweenSteps(LogicController *logicController, Uint32 timeBetweenSteps) {
  logicController->timeBetweenSteps = timeBetweenSteps;
}
