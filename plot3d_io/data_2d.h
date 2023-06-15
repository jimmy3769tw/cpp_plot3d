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

template<typename T>
class Mydata2D: public Data2D<T>{
 public:
  Mydata2D(int nx, int ny) : Data2D<T>(nx, ny) {
    data.resize(nx*ny, 0);
  }

  T &operator()(int i, int j) override {
    return data.at(Idx(i, j));
  }

  std::vector<T> data;

  int Idx(int i, int j) {
    return i*(this->ny) + j;
  }

};