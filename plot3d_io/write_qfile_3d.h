#pragma once
#include "vector"
#include "string"
#include "cstdio"
#include "iostream"
#include "array"
#include <fstream>
#include "data_3d.h"

class WriteQ3D {
 public:

  template<class T>
  void Write(std::string file_name, Data3D<T>& pressure, Data3D<T>&  u, Data3D<T>&  v, Data3D<T>&  w, Data3D<T>&  density) {
    int nx = pressure.nx;
    int ny = pressure.ny;
    int nz = pressure.nz;

    float mach = 0;
    float alpha = 0;
    float reyn = 0;
    float time = 0;
    int io = 1;

    std::ofstream file;
    int no_block = 1;

    file_name = file_name + ".q";
    file.open(file_name, std::ofstream::binary);

    file.write((char *)(&no_block), sizeof(int));
    file.write((char *)(&nx), sizeof(int));
    file.write((char *)(&ny), sizeof(int));
    file.write((char *)(&nz), sizeof(int));

    file.write((char *)(&mach), sizeof(float));
    file.write((char *)(&alpha), sizeof(float));
    file.write((char *)(&reyn), sizeof(float));
    file.write((char *)(&time), sizeof(float));

    auto Writer = [&](Data3D<T>& which_data) {
      for (size_t k = 0; k < nz; ++k)
        for (size_t j = 0; j < ny; ++j)
          for (size_t i = 0; i < nx; ++i) {
            float temp = which_data(i, j, k);
            file.write((char *)(&temp), sizeof(float));
          }
    };

    Writer(pressure);
    Writer(u);
    Writer(v);
    Writer(w);
    Writer(density);

  }
 private:
};
