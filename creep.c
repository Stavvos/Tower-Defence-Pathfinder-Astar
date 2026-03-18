#include "utils.h"
#include "raylib.h"
#include "raymath.h"

void moveCreep(Vector3* currentPos, Vector3 targetPos, int* index)
{
  //move towrds avoids decay as the creep is approaching the target. Therefore in this case more suitable than Vector3Lerp().
  *currentPos = Vector3MoveTowards(*currentPos, targetPos, 0.1);

  //claculate the distance between current and target pos. Use te Vector3DistanceSqr() function as it avoids using square
  //root calculations.
  float squaredDist = Vector3DistanceSqr(*currentPos, targetPos);

  if (squaredDist < 0.000001f)
  {
    (*index)++;
  }
}

void creepMovementHandler(Vector3* currentPos, Vector3 targetPos, int* index, int pathSize)
{
  if (*index >= pathSize)
  {
    return; //stop moving the creep
  }

  moveCreep(currentPos, targetPos, index);
}
