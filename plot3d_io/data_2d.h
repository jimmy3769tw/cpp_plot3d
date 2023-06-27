#pragma once
#include "vector"

template<typename T>
class Data2D{
 public:
  Data2D(int nx, int ny) : nx(nx), ny(ny) {}

  virtual T & operator () (int i, int j) = 0;
  int nx;
  int ny;
};
