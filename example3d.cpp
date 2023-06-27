#include <iostream>
#include "plot3d_io/write_xfile_3d.h"
#include "plot3d_io/write_qfile_3d.h"



template<typename T>
class Mydata3D: public Data3D<T>{
 public:
  std::vector<T> data;

  Mydata3D(int nx, int ny, int nz) : Data3D<T>(nx, ny, nz) {
    data.resize(nx*nz*ny, 0);
  }

  T &operator()(int i, int j, int k) override {
    return data.at(Idx(i, j, k));
  }

  int Idx(int i, int j, int k) {
    return i*(this->nz*this->ny) + j*(this->nz)+k;
  }
};


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

int main() {
  example2D();
  return 0;
}
