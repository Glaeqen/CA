#include "View.h"
#include "../Application.h"

View initView(){
  View object;
  object.windowWidth = width;
  object.windowHeight = height;

  object.window = SDL_CreateWindow("CA", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height,
                                   SDL_WINDOW_OPENGL);

  if (!object.window) {
    fprintf(stderr, "Could not create a window.\n");
    exit(-1);
  }

  object.renderer = SDL_CreateRenderer(object.window, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);

  object.cellsArraySize = logic->sizeCAArray * logic->sizeCAArray;
  object.cellsArray = (SDL_Rect *) malloc(sizeof(SDL_Rect) * object.cellsArraySize);

  /* Set up sizes of rectangles */
  int sideArraySize = logic->sizeCAArray;
  int singleCellSize = width / sideArraySize;
  for (int i = 0; i < sideArraySize; ++i) {
    for (int j = 0; j < sideArraySize; ++j) {
      object.cellsArray[sideArraySize * i + j].x = singleCellSize * i;
      object.cellsArray[sideArraySize * i + j].y = singleCellSize * j;
      object.cellsArray[sideArraySize * i + j].h = object.cellsArray[sideArraySize * i + j].w = singleCellSize;
    }
  }

  // Dead - dark green
  object.colorsArray[0][0] = 5;
  object.colorsArray[0][1] = 71;
  object.colorsArray[0][2] = 26;
  // Alive - green
  object.colorsArray[1][0] = 60;
  object.colorsArray[1][1] = 255;
  object.colorsArray[1][2] = 0;

  return object;
}

int siema(){
  Application a;
  mainLoop(&a);
}
