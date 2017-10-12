#include "Config.h"
/* Temporary solution for a Config input */

void setupStartingCAPlanar(LogicState *logicState) {
  /* planar[logicState->size / 2][logicState->size / 2] = 1; */
  /* planar[logicState->size / 2 - 1][logicState->size / 2] = 1; */
  /* planar[logicState->size / 2 - 2][logicState->size / 2] = 1; */
  /* planar[logicState->size / 2 - 2][logicState->size / 2 + 1] = 1; */
  /* planar[logicState->size / 2 - 1][logicState->size / 2 + 2] = 1; */
  for (int i=0; i<(logicState->sizeCAArray*logicState->sizeCAArray)*5/10; ++i) {
    logicState->currentCAArray[rand()%logicState->sizeCAArray][rand()%logicState->sizeCAArray] = 1;
  }
}

State nextStepStateValue(const LogicState *logicState, int posX, int posY) {
  /* Use getStateValue() to get appropriate state */
  State currentCell = getStateValue(logicState, posX, posY);
  int sum = 0;
  for (int i = -1; i < 2; ++i) {
    for (int j = -1; j < 2; ++j) {
      if (i || j)
        sum += getStateValue(logicState, posX + i, posY + j);
    }
  }

  if (currentCell) {
    if(sum == 2 || sum == 3)
      return 1;
    else
      return 0;
  }
  else {
    if(sum == 3)
      return 1;
    else
      return 0;
  }
}
