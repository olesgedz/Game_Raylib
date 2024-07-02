#include <raylib.h>

#include "Grid.hpp"

int main() {
  Color Grey = {20, 20, 20, 255};
  const int WINDOW_WIDTH = 750;
  const int WINDOW_HEIGHT = 750;
  const int CELL_SIZE = 25;
  InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Game of Life");

  Grid grid(WINDOW_WIDTH, WINDOW_HEIGHT, CELL_SIZE);
  SetTargetFPS(60);
  while (!WindowShouldClose()) {
    // Event processing

    // Updating

    // Rendering
    BeginDrawing();
    ClearBackground(Grey);
    grid.render();
    EndDrawing();
  }

  CloseWindow();
}