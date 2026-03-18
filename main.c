#include "raylib.h"
#include "utils.h"
#include "initialise.c"
#include "render.c"
#include <math.h>
#include <stddef.h>
#include <stdio.h>
#include "path.c"
#include "creep.c"

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
  int pathSize = 19;
  
  //initilaise creep and creep movement variables
  Creep creep;
  initCreep(&creep, path);

  // Main game loop
  while (!WindowShouldClose())    
  {
    
    UpdateCamera(&camera, CAMERA_FREE);
    
    //update states 
    handleChangePath(&changePath, points, path, &creep);
    creepMovementHandler(&creep.pos, path[creep.targetPosIndex].pos, &creep.targetPosIndex, pathSize);

    BeginDrawing();
      ClearBackground(RAYWHITE);
   
      BeginMode3D(camera);
        renderPoints(points);
	renderPath(path);
	renderBarriers(points);
	renderCreep(creep.pos);
      EndMode3D();
    EndDrawing();
  }

  CloseWindow();       

  return 0;
}
