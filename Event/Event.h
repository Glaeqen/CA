#pragma once

typedef struct {
  char isRunning;
  char keyPressed;
} Event;

Event initEvent();

void handleEvents(Event *event);
