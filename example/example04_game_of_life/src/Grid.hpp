#pragma once

#include <vector>

class Grid
{
 public:

  Grid(int width, int height, int cellSize) :
    _rows(height / cellSize), _colums(width / cellSize), _cellSize(cellSize), cells(_rows, std::vector<bool>(_colums, false))
    {}
  void render();

  private:
  int _rows;
  int _colums;
  int _cellSize;
  std::vector<std::vector<bool>> cells;
};
