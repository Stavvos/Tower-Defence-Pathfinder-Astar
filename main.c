#include "raylib.h"
#include "utils.h"
#include "initialise.c"
#include "render.c"

int main(void)
{
  const int screenWidth = GetScreenWidth();
  const int screenHeight = GetScreenHeight();

  InitWindow(screenWidth, screenHeight, "Pathfinder Astar");

  SetTargetFPS(60);             

  Camera3D camera = {0};
  initCamera(&camera);

  //initialise the maze
  Point points[ROWS][COLS];
  initPointsPos(points);
  initPointsState(points);

  // Main game loop
  while (!WindowShouldClose())    
  {
    UpdateCamera(&camera, CAMERA_FREE);

    BeginDrawing();
      ClearBackground(RAYWHITE);
   
      BeginMode3D(camera);
        renderPoints(points);
      EndMode3D();

    EndDrawing();
  }

    CloseWindow();        // Close window and OpenGL context

    return 0;
}
