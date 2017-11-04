#include "ViewHolder.h"

void initViewHolder(ViewHolder *viewHolder, int width, int height) {
  viewHolder->window = SDL_CreateWindow("CA", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height,
                                        SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);

  if (!viewHolder->window) {
    SDL_Log("Could not create a window.\n");
    exit(-1);
  }

  viewHolder->renderer = SDL_CreateRenderer(viewHolder->window, -1,
                                            SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);
}

void freeViewHolder(ViewHolder *viewHolder) {
}

void clearScreenViewHolder(ViewHolder *viewHolder){
  SDL_SetRenderDrawColor(viewHolder->renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
  SDL_RenderClear(viewHolder->renderer);
}
