#include <SDL2/SDL_events.h>
#include "Event.h"

static void resetEvent(Event *event);

void initEvent(Event *event) {
  event->isRunning = 1;
  event->keyPressed = 0;
  event->windowResized = false;
}

void handleEvents(Event *event) {
  resetEvent(event);
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
      case SDL_WINDOWEVENT:
        if (e.window.event == SDL_WINDOWEVENT_RESIZED)
          event->windowResized = true;
    }
  }
}

void freeEvent(Event *event) {

}

void resetEvent(Event *event) {
  initEvent(event);
}
