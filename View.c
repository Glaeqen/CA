#include "View.h"

View initView(int width, int height, LogicState* logicState) {
  View object;
  object.windowWidth = width;
  object.windowHeight = height;

  object.window = SDL_CreateWindow("CA", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_OPENGL);

  if(!object.window){
    fprintf(stderr, "Could not create a window.\n");
    exit(-1);
  }

  object.renderer = SDL_CreateRenderer(object.window, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);

  object.cellsArraySize = logicState->sizeCAArray*logicState->sizeCAArray;
  object.cellsArray = (SDL_Rect *) malloc(sizeof(SDL_Rect)*object.cellsArraySize);
  /* Set up sizes of rectangles */
  int sideArraySize = logicState->sizeCAArray;
  int singleCellSize = width/sideArraySize;
  for (int i=0; i<sideArraySize; ++i) {
    for (int j=0; j<sideArraySize; ++j) {
      object.cellsArray[sideArraySize*i + j].x = singleCellSize * i;
      object.cellsArray[sideArraySize*i + j].y = singleCellSize * j;
      object.cellsArray[sideArraySize*i + j].h = object.cellsArray[sideArraySize*i + j].w = singleCellSize;
    }
  }

  object.colorsArraySize = logicState->amountOfStates;
  object.colorsArray = (Uint8(*)[3])malloc(sizeof(Uint8[3])*object.colorsArraySize);
  for (int i=0; i<object.colorsArraySize; ++i) {
    for (int j=0; j<3; ++j) {
      object.colorsArray[i][j] = rand() % 256;
    }
  }

  return object;
}

void printCells(LogicState *l, View *v){
  View object = *v;

  int sideArraySize = l->sizeCAArray;
  for (int i=0; i<sideArraySize; ++i) {
    for (int j=0; j<sideArraySize; ++j) {
      printf("x: %d, y: %d, w: %d, h: %d\n", object.cellsArray[sideArraySize*i + j].x, object.cellsArray[sideArraySize*i + j].y, object.cellsArray[sideArraySize*i + j].w, object.cellsArray[sideArraySize*i + j].h);
    }
  }
}

void freeView(View* view) {
  free(view->cellsArray);
  view->cellsArray = 0;
  free(view->colorsArray);
  view->colorsArray = 0;
}

void drawLogic(View *view, LogicState *logicState){
  int sideArraySize = logicState->sizeCAArray;
  for (int i=0; i<sideArraySize; ++i) {
    for (int j=0; j<sideArraySize; ++j) {
      SDL_SetRenderDrawColor(view->renderer,
                             view->colorsArray[(int)getStateValue(logicState, i, j)][0], /* Red */
                             view->colorsArray[(int)getStateValue(logicState, i, j)][1], /* Green */
                             view->colorsArray[(int)getStateValue(logicState, i, j)][2], /* Blue */
                             SDL_ALPHA_OPAQUE);
      SDL_RenderFillRect(view->renderer, &view->cellsArray[sideArraySize*i + j]);
      SDL_RenderDrawRect(view->renderer, &view->cellsArray[sideArraySize*i + j]);
    }
  }
  SDL_RenderPresent(view->renderer);
}



