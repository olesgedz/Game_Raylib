#include <raylib.h>
#include <iostream>

#include "Simulation.hpp"

int main() {
  Color Grey = {35, 35, 35, 255};
  const int WINDOW_WIDTH = 750;
  const int WINDOW_HEIGHT = 750;
  const int CELL_SIZE = 25;

  InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Game of Life");
  Simulation simulation(WINDOW_WIDTH / CELL_SIZE, WINDOW_HEIGHT / CELL_SIZE, CELL_SIZE);
  SetTargetFPS(12);
  while (!WindowShouldClose()) {
    // Event processing
    if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
      Vector2 mousePos = GetMousePosition();
      simulation.toggleCell(mousePos.x / CELL_SIZE, mousePos.y / CELL_SIZE);
    }


    if (IsKeyPressed(KEY_SPACE)) {
      if (simulation.isRunning()) {
        simulation.stop();
      } else {
        simulation.start();
      }
    }
    if (IsKeyPressed(KEY_R)) {
      simulation.randomize();
    }
    if (IsKeyPressed(KEY_C)) {
      simulation.clear();
    }
    // Updating
    simulation.update();
    // Rendering
    BeginDrawing();
    ClearBackground(Grey);
    simulation.draw();
    EndDrawing();
  }

  CloseWindow();
}