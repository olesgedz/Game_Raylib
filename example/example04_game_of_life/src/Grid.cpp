#include "Grid.hpp"

#include <raylib.h>

void Grid::render() {
  for (int i = 0; i < _rows; i++) {
    for (int j = 0; j < _colums; j++) {
      Color color = cells[i][j] ? Color{0, 255, 0, 255} : Color{55, 55, 55, 255};
      DrawRectangle(j * _cellSize, i * _cellSize, _cellSize - 1, _cellSize - 1, color);
    }
  }
}
// https://www.youtube.com/watch?v=daFYGrXq0aw