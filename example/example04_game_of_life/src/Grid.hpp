#pragma once

#include <vector>

class Grid {
 public:

  Grid(int width, int height, int cellSize) :
    _rows(height),
        _columns(width), _cellSize(cellSize),
        _cells(_rows, std::vector<bool>(_columns, false))
    {}
  void render();
  void setCell(int x, int y, bool state);
  bool getCell(int x, int y) const;
  bool isWithInBound(int x, int y) const;
  int getRows() const { return _rows; }
  int getColumns() const { return _columns; }
  void randomize();
  void clear();
  private:
    int _rows;
    int _columns;
    int _cellSize;
    std::vector<std::vector<bool>> _cells;
};
