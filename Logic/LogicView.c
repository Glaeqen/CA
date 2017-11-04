#include "LogicView.h"
#include "LogicController.h"
#include "../ViewHolder/ViewHolder.h"
#include "LogicModel.h"

void initLogicView(LogicView *logicView, LogicController *logicController, ViewHolder *viewHolder) {
  logicView->logicController = logicController;
  logicView->viewHolder = viewHolder;

  int sizeX = logicView->cellsArraySizeX = getSizeX(logicController->logicModel);
  int sizeY = logicView->cellsArraySizeY = getSizeY(logicController->logicModel);
  logicView->cellsArray = (SDL_Rect *) malloc(sizeof(SDL_Rect) * sizeX * sizeY);

  /* Set up sizes of rectangles */
  int singleCellSizeX, singleCellSizeY;
  SDL_GetWindowSize(viewHolder->window, &singleCellSizeX, &singleCellSizeY);
  singleCellSizeX /= sizeX;
  singleCellSizeY /= sizeY;
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
      SDL_SetRenderDrawColor(logicView->viewHolder->renderer,
                             logicView->colorsArray[(int) getStateValue(logicView->logicController->logicModel, x,
                                                                        y)][0], /* Red */
                             logicView->colorsArray[(int) getStateValue(logicView->logicController->logicModel, x,
                                                                        y)][1], /* Green */
                             logicView->colorsArray[(int) getStateValue(logicView->logicController->logicModel, x,
                                                                        y)][2], /* Blue */
                             SDL_ALPHA_OPAQUE);
      SDL_RenderFillRect(logicView->viewHolder->renderer, &logicView->cellsArray[sizeX * y + x]);
      SDL_RenderDrawRect(logicView->viewHolder->renderer, &logicView->cellsArray[sizeX * y + x]);
    }
  }
  SDL_RenderPresent(logicView->viewHolder->renderer);
}

void reInitLogicView(LogicView *logicView) {
  freeLogicView(logicView);
  initLogicView(logicView, logicView->logicController, logicView->viewHolder);
  int sizeX, sizeY;
  SDL_GetWindowSize(logicView->viewHolder->window, &sizeX, &sizeY);
  sizeX = sizeX/logicView->cellsArraySizeX*logicView->cellsArraySizeX;
  sizeY = sizeY/logicView->cellsArraySizeY*logicView->cellsArraySizeY;
  SDL_SetWindowSize(logicView->viewHolder->window, sizeX, sizeY);
}
