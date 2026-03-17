#include "raylib.h"

void renderPath(Point* head)
{
  Point *current = head;

  while (current != NULL)
  {
    if (current->pointState == VALID)
    {
      DrawCube(current->pos, 3.0f, 3.0f, 3.0f, GREEN);
    }
    else if (current->pointState == START)
    {
      DrawCube(current->pos, 3.0f, 3.0f, 3.0f, BROWN);
    }
    else if (current->pointState == GOAL)
    {
      DrawCube(current->pos, 3.0f, 3.0f, 3.0f, RED);
    }
    
    current = current->parent;
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
