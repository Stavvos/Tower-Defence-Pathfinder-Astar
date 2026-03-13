#include "raylib.h"

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
