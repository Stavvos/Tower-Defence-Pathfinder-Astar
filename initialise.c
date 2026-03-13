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

void initPoints(Point points[ROWS][COLS])
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
