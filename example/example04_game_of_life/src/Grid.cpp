#include "Grid.hpp"

#include <raylib.h>

#include <iostream>

Grid::Grid(int rows, int columns, int cellSize) : _rows(rows), _columns(columns), _cellSize(cellSize) {
  for (int i = 0; i < _rows; i++) {
    _cells.emplace_back(_columns, Cell(false, 0));
  }
}

void Grid::render() {
  for (int i = 0; i < _rows; i++) {
    for (int j = 0; j < _columns; j++) {
      Color color = Color{55, 55, 55, 255};
      if (_cells[i][j].alive) {
        unsigned char green = _cells[i][j].numberOfFramesAlive + 50;
        unsigned char red = 0;
        unsigned char blue = 0;
        if (green > 255) red = _cells[i][j].numberOfFramesAlive - 255;
        if (red > 610) blue = _cells[i][j].numberOfFramesAlive - 560;
        color = Color{red, green, blue, 255};
      }
      DrawRectangle(i * _cellSize, j * _cellSize, _cellSize - 1, _cellSize - 1, color);
    }
  }
}

void Grid::setCell(int x, int y, bool state) {
  if (isWithInBound(x, y)) {
    _cells[y][x].alive = state;
  }
}

bool Grid::getCell(int x, int y) const {
  if (isWithInBound(x, y)) {
    return _cells[y][x].alive;
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
      _cells[i][j].alive = (random == 4);
    }
  }
}

void Grid::clear() {
  for (int i = 0; i < _rows; i++) {
    for (int j = 0; j < _columns; j++) {
      _cells[i][j].alive = false;
    }
  }
}
