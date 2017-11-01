#pragma once

#include "Logic/Logic.h"

enum {
  /* Size of the CA planar. */
        CA_PLANAR_SIZE = 40,
  /* Time between next steps when in auto mode. */
        CA_PLANAR_NEXT_STEP_TIME = 100,
  /* Modes for planar's edges.
     -1 - Wrap around
     number != -1 -> Edge immutable state is `number` state.
  */
        CA_PLANAR_EDGE_CONFIG = -1
};

void setupStartingCAPlanar(Logic *logic);

State nextStepStateValue(const Logic *logic, int posX, int posY);
