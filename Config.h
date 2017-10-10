enum {
  /* Size of the CA planar. */
  CA_PLANAR_SIZE = 40,
  /* Time between next steps when in auto mode. */
  CA_PLANAR_NEXT_STEP_TIME = 30,
  /* Modes for planar's edges.
     -1 - Wrap around
     number != -1 -> Edge immutable state is `number` state.
  */
  CA_PLANAR_EDGE_CONFIG = -1
};

void setupStartingCAPlanar(State **planar) {
  /* planar[CA_PLANAR_SIZE / 2][CA_PLANAR_SIZE / 2] = 1; */
  /* planar[CA_PLANAR_SIZE / 2 - 1][CA_PLANAR_SIZE / 2] = 1; */
  /* planar[CA_PLANAR_SIZE / 2 - 2][CA_PLANAR_SIZE / 2] = 1; */
  /* planar[CA_PLANAR_SIZE / 2 - 2][CA_PLANAR_SIZE / 2 + 1] = 1; */
  /* planar[CA_PLANAR_SIZE / 2 - 1][CA_PLANAR_SIZE / 2 + 2] = 1; */
  for (int i=0; i<(CA_PLANAR_SIZE*CA_PLANAR_SIZE)*8/10; ++i) {
    planar[rand()%CA_PLANAR_SIZE][rand()%CA_PLANAR_SIZE] = 1;
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
