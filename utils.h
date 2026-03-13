#include "raylib.h"

#ifndef UTILS_H
#define UTILS_H

#define ROWS 10
#define COLS 10
#define SPACING 3

typedef enum PointState
{
  VALID,
  NOTVALID,
  START,
  GOAL
} PointState;

typedef struct Point
{
  Vector3 pos;
  PointState pointState;
} Point; 

#endif
