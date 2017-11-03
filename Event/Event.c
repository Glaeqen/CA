#include <SDL2/SDL_events.h>
#include "Event.h"

void initEvent(Event *event) {
  event->isRunning = 1;
  event->keyPressed = 0;
}

void handleEvents(Event *event) {
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    switch (e.type) {
      case SDL_QUIT:
        event->isRunning = 0;
        break;
      case SDL_KEYDOWN:
        event->keyPressed = e.key.keysym.sym;
        break;
      case SDL_KEYUP:
        event->keyPressed = 0;
        break;
    }
  }
}

void freeEvent(Event *event) {

}
