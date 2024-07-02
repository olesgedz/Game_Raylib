#include "Simulation.hpp"

#include <iostream>
#include <utility>
#include <vector>

void Simulation::draw() { _grid.render(); }

void Simulation::setCell(int x, int y, bool state) { _grid.setCell(x, y, state); }

int Simulation::_countLiveNeighbors(int x, int y) {
  int liveNumbers = 0;

  for (const auto& offset : _offsetNeighbors) {
    liveNumbers += _grid.getCell((x + offset[0] + _grid.getColumns()) % _grid.getColumns(),
                                 (y + offset[1] + _grid.getRows()) % _grid.getRows());
  }

  return liveNumbers;
}

void Simulation::update() {
  if (!isRunning()) {
    return;
  }
  for (int j = 0; j < _grid.getRows(); j++) {
    for (int k = 0; k < _grid.getColumns(); k++) {
      int liveNeighbors = _countLiveNeighbors(k, j);
      bool cellState = _grid.getCell(k, j);
      if (cellState) {
        if (liveNeighbors > 3 || liveNeighbors < 2) {
          _gridTemp.setCell(k, j, false);
        } else {
          _gridTemp.setCell(k, j, true);
        }
      } else {
        if (liveNeighbors == 3) {
          _gridTemp.setCell(k, j, true);
        } else {
          _gridTemp.setCell(k, j, false);
        }
      }
    }
  }
  _grid = _gridTemp;
}

void Simulation::randomize() {
  if (!isRunning()) {
    _grid.randomize();
  }
}

void Simulation::clear() {
  if (!isRunning()) {
    _grid.clear();
  }
}
void Simulation::toggleCell(int x, int y) { setCell(x, y, !_grid.getCell(x, y)); }
