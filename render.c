#include "raylib.h"

void drawPath()
{
  Point *curr = goalNode;
  while (curr != NULL)
  {
    if (curr->pointState == VALID)
    {
      DrawCube(curr->pos, 3.0f, 3.0f, 3.0f, GREEN);
    }
    curr = curr->parent;
  }
}

void renderPoints(Point points[ROWS][COLS])
{
  for (int i = 0; i < ROWS; i++)
  {
    for (int j = 0; j < COLS; j++)
    {
      if (points[i][j].pointState == START)
      {
        DrawCube(points[i][j].pos, 3.0f, 3.0f, 3.0f, BROWN);
      }
      else if (points[i][j].pointState == GOAL)
      {
        DrawCube(points[i][j].pos, 3.0f, 3.0f, 3.0f, RED);
      }
      else if (points[i][j].pointState == NOTVALID)
      {
        DrawCube(points[i][j].pos, 3.0f, 3.0f, 3.0f, BLUE);
      }
      else if (points[i][j].pointState == VALID)
      {
        DrawSphere(points[i][j].pos, 0.1, BLACK);
      }
    }
  }
}	
