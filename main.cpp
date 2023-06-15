#include <iostream>
#include "plot3d_io/write_xfile_3d.h"
#include "plot3d_io/write_qfile_3d.h"

#include "plot3d_io/write_qfile_2d.h"
#include "plot3d_io/write_xfile_2d.h"
#include "plot3d_io/data_2d.h"

void example3D() {
  int nx = 10;
  double lx = 1;
  double dx = lx/nx;
  std::vector<double> x(nx);
  for (int i = 0; i < nx; i++) {
    x.at(i) = dx*i;
  }
  WriteX3D data_3d_io_mesh;
  data_3d_io_mesh.Writ("test3d", x, x, x);

  WriteQ3D data_3d_io_q;
  Mydata3D<double> pressure(nx, nx, nx);
  data_3d_io_q.Write("test3d", pressure, pressure, pressure, pressure, pressure);
}

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
int main() {
  example2D();
  return 0;
}
