#pragma once

#include <vector>

class Grid {
 public:

  Grid(int width, int height, int cellSize);

  void render();
  void setCell(int x, int y, bool state);
  bool getCell(int x, int y) const;
  bool isWithInBound(int x, int y) const;
  int getRows() const { return _rows; }
  int getColumns() const { return _columns; }
  void randomize();
  void clear();
  struct Cell {
    bool alive = false;
    int numberOfFramesAlive = 0;
  };
  void setCellLife(int x, int y, int number) {  _cells[y][x].numberOfFramesAlive = number; }
  int getCellLife(int x, int y) { return _cells[y][x].numberOfFramesAlive; }

  private:

    int _rows;
    int _columns;
    int _cellSize;
    std::vector<std::vector<Cell>> _cells;
};
