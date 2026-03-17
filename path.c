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

Point* reversePath(Point* head)
{
  Point *previous = NULL;
  Point *current = head;
  Point *next = NULL;

  while(current != NULL)
  {
    next = current->parent;
    current->parent = previous;
    previous = current;
    current = next;
  }

  return previous;
}

void handleChangePath(bool* changePath, Point points[ROWS][COLS], Point* head)
{
  if (IsKeyPressed(KEY_P) && !(*changePath))
  {
    points[1][0].pointState = NOTVALID;
    *changePath = true;
    ResetGridForAStar(points);
    Astar();
    head = reversePath(goalNode);
  }
  else if (IsKeyPressed(KEY_P) && *changePath)
  {
    points[1][0].pointState = VALID;
    *changePath = false;
    ResetGridForAStar(points);
    Astar();
    head = reversePath(goalNode);
  }
}
