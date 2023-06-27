#pragma once

#include "plot3d_io/write_qfile_2d.h"
#include "plot3d_io/write_xfile_2d.h"
#include "plot3d_io/data_2d.h"



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

void example2D(){
  int nx = 10;
  double lx = 1;
  double dx = lx/nx;
  std::vector<double> x(nx);
  for (int i = 0; i < nx; i++) {
    x.at(i) = dx*i;
  }
  WriteX2D data_2d_io_mesh;
  data_2d_io_mesh.Writ("test2d", x, x);

  WriteQ2D data_3d_io_q;
  Mydata2D<double> pressure(nx, nx);

  data_3d_io_q.Write("test2d", pressure, pressure, pressure, pressure);
}