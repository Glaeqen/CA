#pragma once

enum {
  /* Size of the CA planar. */
        DEFAULT_PLANAR_SIZE = 40,
  /* Default window resolution */
        DEFAULT_WINDOW_SIZE_XY = 10 * DEFAULT_PLANAR_SIZE,
  /* Time between next steps when in auto mode. [ms] */
        DEFAULT_NEXT_STEP_TIME = 100,
  /* Modes for planar's edges.
     -1 - Wrap around
     number != -1 -> Edge immutable state is `number` state.
  */
        DEFAULT_EDGE_CONFIG = -1,
  /* Default alive percentage <0 - 100> */
        DEFAULT_ALIVE_PERCENTAGE = 50,
  /* Default state of triggering further steps (0/1) */
        DEFAULT_IS_MANUAL_BOOLEAN = 1
};
