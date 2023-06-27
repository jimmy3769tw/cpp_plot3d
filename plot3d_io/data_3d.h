#pragma once

template<typename T>
class Data3D{
public:
  Data3D(int nx, int ny, int nz) : nx(nx), ny(ny), nz(nz) {}

  virtual T & operator () (int i, int j, int k) = 0;
  int nx;
  int ny;
  int nz;
};
