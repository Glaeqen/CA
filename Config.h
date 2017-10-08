enum{
  /* Size of the CA planar. */
  CA_PLANAR_SIZE = 10,
  /* Time between next steps when in auto mode. */
  CA_PLANAR_NEXT_STEP_TIME = 1000,
  /* Modes for planar's edges.
     -1 - Wrap around
     number != -1 -> Edge immutable state is `number` state.
  */
  CA_PLANAR_EDGE_CONFIG = -1
};

State nextStepStateValue(const LogicState *logicState, int posX, int posY){
  /* Use getStateValue() to get appropriate state */
  return 0;
}
