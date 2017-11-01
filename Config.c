#include "Config.h"

/* Temporary solution for a Config input */

void setupStartingCAPlanar(Logic *logic) {
  for (int i = 0; i < (logic->sizeCAArray * logic->sizeCAArray) * 5 / 10; ++i) {
    logic->currentCAArray[(rand() % logic->sizeCAArray) * logic->sizeCAArray +
                               rand() % logic->sizeCAArray] = 1;
  }
}

State nextStepStateValue(const Logic *logic, int posX, int posY) {
  /* Use getStateValue() to get appropriate state */
  State currentCell = getStateValue(logic, posX, posY);
  int sum = 0;
  for (int i = -1; i < 2; ++i) {
    for (int j = -1; j < 2; ++j) {
      if (i || j)
        sum += getStateValue(logic, posX + i, posY + j);
    }
  }

  if (currentCell) {
    if (sum == 2 || sum == 3)
      return 1;
    else
      return 0;
  } else {
    if (sum == 3)
      return 1;
    else
      return 0;
  }
}
