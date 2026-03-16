#include "raylib.h"
#include "utils.h"
#include "initialise.c"
#include "render.c"
#include <math.h>
#include <stddef.h>
#include <stdio.h>
#include "Astar.c"

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

  // Main game loop
  while (!WindowShouldClose())    
  {
    
    UpdateCamera(&camera, CAMERA_FREE);
    
    handleChangePath(&changePath, points);

    BeginDrawing();
      ClearBackground(RAYWHITE);
   
      BeginMode3D(camera);
        renderPoints(points);
	drawPath();
      EndMode3D();
      
    EndDrawing();
  }

  CloseWindow();        // Close window and OpenGL context

  return 0;
}
