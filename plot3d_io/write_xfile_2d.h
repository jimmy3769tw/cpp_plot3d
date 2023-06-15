#pragma once

#include "vector"
#include "string"
#include "cstdio"
#include "iostream"
#include "array"

class WriteX2D{
 public:
  template<class T>
  void Writ(std::string file_name, std::vector<T>& xc, std::vector<T>& yc) {

    std::string file_name_ = file_name + ".x";
    FILE * fptr;
    fptr = std::fopen(file_name_.c_str(),"wb");
    int nx = xc.size();
    int ny = yc.size();
    std::vector<float> xc_out(xc.begin(), xc.end());
    std::vector<float> yc_out(yc.begin(), yc.end());
    fwrite(&Nblock, sizeof(int), 1, fptr);
    fwrite(&nx, sizeof(int), 1, fptr);
    fwrite(&ny, sizeof(int), 1, fptr);

    for (size_t j = 0; j < ny; ++j)
      for (size_t i = 0; i < nx; ++i)
        fwrite(&xc_out[i], sizeof(float), 1, fptr);

    for (size_t j = 0; j < ny; ++j)
      for (size_t i = 0; i < nx; ++i)
        fwrite(&yc_out[j], sizeof(float), 1, fptr);

    fclose(fptr);
  }
 private:
  int Nblock = 1;

};