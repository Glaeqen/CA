#include "Event.h"

/* Implementation of the proper config functions goes here. */
#include "../Config.h"

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

void updateLogic(Event *event, Logic *logic) {
  if (event->keyPressed == 'a') logic->isManual = false;
  if (event->keyPressed == 'm') logic->isManual = true;
  if (logic->isManual) {
    if (event->keyPressed == 'n') {
      nextStep(logic);
      event->keyPressed = 0;
    };
  } else {
    Uint32 currentTime = SDL_GetTicks();
    if (currentTime - logic->timeLastLogicUpdate > CA_PLANAR_NEXT_STEP_TIME) {
      nextStep(logic);
      logic->timeLastLogicUpdate = currentTime;
    }
  }
}

void updateView(Event *event, View *view) {
}
