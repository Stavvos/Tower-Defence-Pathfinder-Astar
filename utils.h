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
  int row;
  int col;
  PointState pointState;
  float f;
  float h;
  float g;
  bool open;
  bool closed;
  struct Point *parent;
} Point; 

typedef struct Creep
{
  Vector3 pos;
  int targetPosIndex;
} Creep;

typedef struct Path
{
  int pathSize;
  bool changePath;
  Point points[ROWS*COLS];
} Path;

extern Point *startNode;
extern Point *goalNode;
extern Point points[ROWS][COLS];
#endif
