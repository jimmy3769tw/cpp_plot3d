cmake_minimum_required(VERSION 3.25)
project(cpp_plot3d)

set(CMAKE_CXX_STANDARD 17)

add_executable(cpp_plot3d example3d.cpp plot3d_io/write_xfile_3d.h plot3d_io/write_qfile_3d.h plot3d_io/data_3d.h)
add_executable(cpp_plot2d example2d.cpp plot3d_io/data_2d.h plot3d_io/write_qfile_2d.h plot3d_io/write_xfile_2d.h)
