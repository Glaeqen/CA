/* Little program showcasing some cellular automaton/s. By Glaeqen. */ 
#include <SDL2/SDL.h>
#include <stdio.h>

int main(){
  SDL_Window *window = NULL;
  SDL_Renderer *renderer = NULL;

  SDL_Init(SDL_INIT_VIDEO);
  window = SDL_CreateWindow("CA", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 10, 10, SDL_WINDOW_OPENGL);

  if(!window){
    fprintf(stderr, "Could not create a window.\n");
    return -1;
  }

  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

  SDL_Event event;
  SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);

  while(1){
    /* if(SDL_PollEvent(&event)){ */
    /*   if(event.type == SDL_QUIT) break; */
    /* } */
    if(SDL_PollEvent(&event)){
      if(event.type == SDL_QUIT) break;
      printf("0x%X\n", event.type);
    }
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
  }

  SDL_Quit();
  return 0;
}
