#include "utils.h"
#include "raylib.h"

float Heuristic(Point *a, Point *b)
{
  int ax = a->pos.x;
  int ay = a->pos.z;
  int bx = b->pos.x;
  int by = b->pos.z;

  return fabs(ax - bx) + fabs(ay - by);
}

Point *GetLowest(Point *list[], int count)
{
  Point *best = list[0];

  for (int i = 1; i < count; i++)
  {
    if (list[i]->f < best->f)
    {
      best = list[i];
    }
  }
    return best;
}

bool Astar()
{
  Point *openList[ROWS * COLS];
  int openCount = 0;

  startNode->open = true;
  openList[openCount++] = startNode;

  while (openCount > 0)
  {
    Point *current = GetLowest(openList, openCount);

    if (current == goalNode)
    {
      return true;
    }

    current->closed = true;

    for (int i = 0; i < openCount; i++)
    {
      if (openList[i] == current)
      {
        openList[i] = openList[--openCount];
        break;
      }
    }
    
    int r = current->row;
    int c = current->col;
    Point *neighbors[4];
    int count = 0;

    if (r > 0) neighbors[count++] = &points[r-1][c];
    if (r < ROWS-1) neighbors[count++] = &points[r+1][c];
    if (c > 0) neighbors[count++] = &points[r][c-1];
    if (c < COLS-1) neighbors[count++] = &points[r][c+1];

    for (int i = 0; i < count; i++)
    {
      Point *n = neighbors[i];

      if (n->closed)
      {
        continue;
      }

      if (n->pointState == NOTVALID)
      {
        continue;
      }

      float tentativeG = current->g + 1;

      if (!n->open || tentativeG < n->g)
      {
        n->parent = current;
        n->g = tentativeG;
        n->h = Heuristic(n, goalNode);
        n->f = n->g + n->h;

        if (!n->open)
        {
          n->open = true;
          openList[openCount++] = n;
        }
      }
    }
  }

  return false;
}

void ResetGridForAStar(Point points[ROWS][COLS])
{
  for (int r = 0; r < ROWS; r++)
  {
    for (int c = 0; c < COLS; c++)
    {
      points[r][c].g = 0;
      points[r][c].h = 0;
      points[r][c].f = 0;
      points[r][c].open = false;
      points[r][c].closed = false;
      points[r][c].parent = NULL;
    }
  }
}

void buildPathArray(Point path[])
{
  //reset the path states 
  for (int i = 0; i < ROWS * COLS; i++)
  {
    path[i].pointState = NOTVALID; 
  }	  
  
  //iterate the linked list from Astar()  
  Point *current = goalNode;
  int index = 0;

  while (current != NULL)
  {
    path[index] = *current;
    index++;
    current = current->parent; 
  }
  
  int end = index - 1;
  int start = 0;
  Point temp = {0};

  //reverse the path array
  while(end > start)
  {
    temp = path[end];
    path[end] = path[start];
    path[start] = temp;

    start++;
    end--;  
  }
  
  //print the array
  for (int i = 0; i < index; i++)
  {
    printf("\n%f %f %f\n", path[i].pos.x, path[i].pos.y, path[i].pos.z);
  }

}

void handleChangePath(bool* changePath, Point points[ROWS][COLS], Point path[])
{
  if (IsKeyPressed(KEY_P) && !(*changePath))
  {
    points[1][0].pointState = NOTVALID;
    *changePath = true;
    ResetGridForAStar(points);
    Astar();
    buildPathArray(path);
  }
  else if (IsKeyPressed(KEY_P) && *changePath)
  {
    points[1][0].pointState = VALID;
    *changePath = false;
    ResetGridForAStar(points);
    Astar();
    buildPathArray(path);
  }
}
