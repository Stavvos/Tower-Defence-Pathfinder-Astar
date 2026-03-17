#include "raylib.h"
#include "utils.h"
#include "initialise.c"
#include "render.c"
#include <math.h>
#include <stddef.h>
#include <stdio.h>
#include "path.c"

int main(void)
{
  const int screenWidth = GetScreenWidth();
  const int screenHeight = GetScreenHeight();

  InitWindow(screenWidth, screenHeight, "Pathfinder Astar");

  SetTargetFPS(60);             

  Camera3D camera = {0};
  initCamera(&camera);

  //initialise the maze
  initPointsPos(points);
  initPointsState(points);
  
  //initialise the path  
  Astar();
  bool changePath = false;
  Point *head = reversePath(goalNode); 

  // Main game loop
  while (!WindowShouldClose())    
  {
    
    UpdateCamera(&camera, CAMERA_FREE);
    
    handleChangePath(&changePath, points, head);
     
    BeginDrawing();
      ClearBackground(RAYWHITE);
   
      BeginMode3D(camera);
        renderPoints(points);
	renderPath(head);
	renderBarriers(points);
      EndMode3D();
    EndDrawing();
  }

  CloseWindow();       

  return 0;
}
