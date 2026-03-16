#include "raylib.h"
#include "utils.h"

void initCamera(Camera3D* camera)
{
  camera->position = (Vector3){ 10.0f, 50.0f, 10.0f }; // Camera position
  camera->target = (Vector3){ 0.0f, 0.0f, 0.0f };      // Camera looking at point
  camera->up = (Vector3){ 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
  camera->fovy = 45.0f;                                // Camera field-of-view Y
  camera->projection = CAMERA_PERSPECTIVE;             // Camera projection type
}

void initPointsPos(Point points[ROWS][COLS])
{
  Vector3 startPos = {0};

  for (int i = 0; i < ROWS; i++)
  {
    startPos.x = 0;
    for (int j = 0; j < COLS; j++)
    {
      points[i][j].pos = startPos;
      startPos = (Vector3){startPos.x + SPACING, startPos.y, startPos.z};
    }
    startPos = (Vector3){startPos.x, startPos.y, startPos.z + SPACING};
  }
}

void initialiseNotValidPoints(Point points[ROWS][COLS], int rows, int cols, int indexRow, int indexCol)
{
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      points[indexRow + i][indexCol + j].pointState = NOTVALID; 
    }
  }
}

void initPointsState(Point points[ROWS][COLS])
{
  
  for (int i = 0; i < ROWS; i++)
  {
    for (int j = 0; j < COLS; j++)
    {
      points[i][j].pointState = VALID;   
    }
  }

  points[0][0].pointState = START;
  points[ROWS - 1][COLS - 1].pointState = GOAL;

  initialiseNotValidPoints(points, 3, 3, 1, 1); 
  initialiseNotValidPoints(points, 3, 3, 6, 1); 
  initialiseNotValidPoints(points, 3, 3, 1, 6); 
  initialiseNotValidPoints(points, 3, 3, 6, 6); 
}
