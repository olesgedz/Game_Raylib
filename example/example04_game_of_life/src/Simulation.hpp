#pragma once
#include <array>
#include <utility>

#include "Grid.hpp"

class Simulation {
 public:
  Simulation(int width, int height, int cellSize) : _grid(width, height, cellSize), _gridTemp(width, height, cellSize) {}

  void randomize();
  void draw();
  void setCell(int x, int y, bool state);
  void update();
  bool isRunning() const { return running; }
  void start() { running = true; }
  void stop() { running = false; }
  void clear();
  void toggleCell(int x, int y);

 private:
  Grid _grid;
  Grid _gridTemp;
  bool running = false;
  const std::array<std::array<int, 2>, 8> _offsetNeighbors = {
        std::array<int, 2>{-1, -1}, std::array<int, 2>{0, -1}, std::array<int, 2>{1, -1},
        std::array<int, 2>{-1, 0}, std::array<int, 2>{1, 0},
        std::array<int, 2>{-1, 1}, std::array<int, 2>{0, 1}, std::array<int, 2>{1, 1}
  };

  int _countLiveNeighbors(int x, int y);


};
