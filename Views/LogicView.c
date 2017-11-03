#include "LogicView.h"
#include "../Controllers/LogicController.h"
#include "View.h"
#include "../Models/LogicModel.h"

void initLogicView(LogicView *logicView, LogicController *logicController, View *view) {
  logicView->logicController = logicController;
  logicView->view = view;

  int sizeX = logicView->cellsArraySizeX = getSizeX(logicController->logicModel);
  int sizeY = logicView->cellsArraySizeY = getSizeY(logicController->logicModel);
  logicView->cellsArray = (SDL_Rect *) malloc(sizeof(SDL_Rect) * sizeX * sizeY);

  /* Set up sizes of rectangles */
  int singleCellSizeX = view->width / sizeX;
  int singleCellSizeY = view->height / sizeY;
  for (int y = 0; y < sizeY; ++y) {
    for (int x = 0; x < sizeX; ++x) {
      logicView->cellsArray[sizeX * y + x].x = singleCellSizeX * x;
      logicView->cellsArray[sizeX * y + x].y = singleCellSizeY * y;
      logicView->cellsArray[sizeX * y + x].h = singleCellSizeY;
      logicView->cellsArray[sizeX * y + x].w = singleCellSizeX;
    }
  }

  // Dead - dark green
  logicView->colorsArray[0][0] = 5;
  logicView->colorsArray[0][1] = 71;
  logicView->colorsArray[0][2] = 26;
  // Alive - green
  logicView->colorsArray[1][0] = 60;
  logicView->colorsArray[1][1] = 255;
  logicView->colorsArray[1][2] = 0;
}

void freeLogicView(LogicView *logicView) {
  if (!logicView) return;
  if (logicView->cellsArray) {
    free(logicView->cellsArray);
    logicView->cellsArray = NULL;
  }
}

void drawLogicView(LogicView *logicView) {
  int sizeX = logicView->cellsArraySizeX;
  int sizeY = logicView->cellsArraySizeY;
  for (int y = 0; y < sizeY; ++y) {
    for (int x = 0; x < sizeX; ++x) {
      SDL_SetRenderDrawColor(logicView->view->renderer,
                             logicView->colorsArray[(int) getStateValue(logicView->logicController->logicModel, x, y)][0], /* Red */
                             logicView->colorsArray[(int) getStateValue(logicView->logicController->logicModel, x, y)][1], /* Green */
                             logicView->colorsArray[(int) getStateValue(logicView->logicController->logicModel, x, y)][2], /* Blue */
                             SDL_ALPHA_OPAQUE);
      SDL_RenderFillRect(logicView->view->renderer, &logicView->cellsArray[sizeX * y + x]);
      SDL_RenderDrawRect(logicView->view->renderer, &logicView->cellsArray[sizeX * y + x]);
    }
  }
  SDL_RenderPresent(logicView->view->renderer);
}



