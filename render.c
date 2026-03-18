#include "raylib.h"

void renderPath(Point path[])
{

  for (int i = 0; i < ROWS * COLS; i++)
  {
    if (path[i].pointState == VALID)
    {
      DrawCube(path[i].pos, 3.0f, 3.0f, 3.0f, GREEN);
    }
    else if (path[i].pointState == START)
    {
      DrawCube(path[i].pos, 3.0f, 3.0f, 3.0f, BROWN);
    }
    else if (path[i].pointState == GOAL)
    {
      DrawCube(path[i].pos, 3.0f, 3.0f, 3.0f, RED);
    }
  }

}

void renderBarriers(Point points[ROWS][COLS])
{
  for (int i = 0; i < ROWS; i++)
  {
    for (int j = 0; j < COLS; j++)
    {
      if(points[i][j].pointState == NOTVALID)
      {
        DrawCube(points[i][j].pos, 3.0f, 3.0f, 3.0f, BLUE);
      }
    }
  }  
}

void renderPoints(Point points[ROWS][COLS])
{
  for (int i = 0; i < ROWS; i++)
  {
    for (int j = 0; j < COLS; j++)
    {
      DrawSphere(points[i][j].pos, 0.1, BLACK);
    }
  }
}

void renderCreep(Vector3 pos)
{
  Vector3 position = (Vector3){pos.x, 2.0f, pos.z};

  DrawCube(position, 1.0f, 1.0f, 1.0f, BLACK);
}
