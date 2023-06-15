#pragma once

#include "vector"
#include "string"
#include "cstdio"
#include "iostream"
#include "array"

class WriteX3D{
 public:

  template<class T>
  void Writ(std::string file_name, std::vector<T>& xc, std::vector<T>& yc, std::vector<T>& zc) {

    std::string file_name_ = file_name + ".x";
    FILE * fptr;
    fptr = std::fopen(file_name_.c_str(),"wb");
    int nx = xc.size();
    int ny = yc.size();
    int nz = zc.size();
    std::vector<float> xc_out(xc.begin(), xc.end());
    std::vector<float> yc_out(yc.begin(), yc.end());
    std::vector<float> zc_out(zc.begin(), zc.end());

    fwrite(&Nblock, sizeof(int), 1, fptr);
    fwrite(&nx, sizeof(int), 1, fptr);
    fwrite(&ny, sizeof(int), 1, fptr);
    fwrite(&nz, sizeof(int), 1, fptr);

    for (size_t k = 0; k < nz; ++k)
      for (size_t j = 0; j < ny; ++j)
        for (size_t i = 0; i < nx; ++i)
          fwrite(&xc_out[i], sizeof(float), 1, fptr);

    for (size_t k = 0; k < nz; ++k)
      for (size_t j = 0; j < ny; ++j)
        for (size_t i = 0; i < nx; ++i)
          fwrite(&yc_out[j], sizeof(float), 1, fptr);

    for (size_t k = 0; k < nz; ++k)
      for (size_t j = 0; j < ny; ++j)
        for (size_t i = 0; i < nx; ++i)
          fwrite(&zc_out[k], sizeof(float ), 1, fptr);

    fclose(fptr);
  }
 private:
  int Nblock = 1;

};