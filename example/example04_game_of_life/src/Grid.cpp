#include "Grid.hpp"

#include <raylib.h>
#include <iostream>

void Grid::render() {
  for (int i = 0; i < _rows; i++) {
    for (int j = 0; j < _columns; j++) {
      Color color = _cells[i][j] ? Color{0, 255, 0, 255} : Color{55, 55, 55, 255};
      DrawRectangle(j * _cellSize, i * _cellSize, _cellSize - 1, _cellSize - 1, color);
    }
  }
}

void Grid::setCell(int x, int y, bool state) {
  if (isWithInBound(x, y)) {
    _cells[y][x] = state;
  }
}

bool Grid::getCell(int x, int y) const {
  if (isWithInBound(x, y)) {
    return _cells[y][x];
  }
  return false;
}
bool Grid::isWithInBound(int x, int y) const {
  if (0 <= x && x < _columns && 0 <= y && y < _rows) {
    return true;
  }
  return false;
}

void Grid::randomize() {
  for (int i = 0; i < _rows; i++) {
    for (int j = 0; j < _columns; j++) {
      int random = GetRandomValue(0, 4);
      _cells[i][j] = (random == 4);
    }
  }
}

void Grid::clear() {
  for (int i = 0; i < _rows; i++) {
    for (int j = 0; j < _columns; j++) {
      _cells[i][j] = false;
    }
  }
}
