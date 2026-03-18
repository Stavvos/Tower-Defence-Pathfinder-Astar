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
  Path path; 
  initPath(&path);
  Astar();
  buildPathArray(path.points);
  
  //initilaise creep and creep movement variables
  Creep creep;
  initCreep(&creep, path.points);

  // Main game loop
  while (!WindowShouldClose())    
  {
    
    UpdateCamera(&camera, CAMERA_FREE);
    
    //update states 
    handleChangePath(&path.changePath, points, path.points, &creep);
    creepMovementHandler(&creep.pos, path.points[creep.targetPosIndex].pos, &creep.targetPosIndex, path.pathSize);
    
    //draw
    BeginDrawing();
      ClearBackground(RAYWHITE);
   
      BeginMode3D(camera);
        renderPoints(points);
	renderPath(path.points);
	renderBarriers(points);
	renderCreep(creep.pos);
      EndMode3D();

    EndDrawing();
  }
  
  //de-initialise
  CloseWindow();       

  return 0;
}
