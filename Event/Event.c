#include <SDL2/SDL_events.h>
#include "Event.h"

Event initEvent() {
  Event object;
  object.isRunning = 1;
  object.keyPressed = 0;
  return object;
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
