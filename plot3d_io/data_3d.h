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