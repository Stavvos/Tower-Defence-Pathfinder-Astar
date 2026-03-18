#include "raylib.h"
#include "utils.h"
#include "initialise.c"
#include "render.c"
#include <math.h>
#include <stddef.h>
#include <stdio.h>
#include "path.c"

void renderCreep(Vector3 pos)
{
  Vector3 position = (Vector3){pos.x, 2.0f, pos.z};

  DrawCube(position, 1.0f, 1.0f, 1.0f, BLACK);
}

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
  Point path[ROWS * COLS];
  buildPathArray(path);

  // Main game loop
  while (!WindowShouldClose())    
  {
    
    UpdateCamera(&camera, CAMERA_FREE);
    
    handleChangePath(&changePath, points, path);
     
    BeginDrawing();
      ClearBackground(RAYWHITE);
   
      BeginMode3D(camera);
        renderPoints(points);
	renderPath(path);
	renderBarriers(points);
	renderCreep(path[0].pos);
      EndMode3D();
    EndDrawing();
  }

  CloseWindow();       

  return 0;
}
