#pragma once

#include <SDL2/SDL.h>

typedef struct ViewHolder {
  SDL_Window *window;
  SDL_Renderer *renderer;
} ViewHolder;

void initViewHolder(ViewHolder *viewHolder, int width, int height);

void freeViewHolder(ViewHolder *viewHolder);

void clearScreenViewHolder(ViewHolder *viewHolder);
