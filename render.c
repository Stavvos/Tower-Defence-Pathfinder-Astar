#include "raylib.h"

void renderPoints(Point points[ROWS][COLS])
{
  for (int i = 0; i < ROWS; i++)
  {
    for (int j = 0; j < COLS; j++)
    {
      if (points[i][j].pointState == START)
      {
        DrawSphere(points[i][j].pos, 0.1, GREEN);
      }
      else if (points[i][j].pointState == GOAL)
      {
        DrawSphere(points[i][j].pos, 0.1, RED);
      }
      else if (points[i][j].pointState == VALID)
      {
        DrawSphere(points[i][j].pos, 0.1, BLACK);
      }
    }
  }
}	
