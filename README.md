# cpp plot3d Output Documentation

This is a documentation for generating Plot3d output files. It supports head-only mode and currently has support for structured grid data with Cartesian coordinate system.

## Features
Cartesian Coordinate Support: The tool is capable of generating Plot3d output files to describe numerical fields with a Cartesian coordinate system. This enables data visualization in software that supports the Plot3d file format.

Structured Grid: The tool can process structured grid data and generate Plot3d output files to store this data. Structured grids consist of regular grid cells, making it convenient for grid-based data processing in software.

Head-Only Output: This tool can generate Plot3d files that only include header information. This means it generates metadata describing the data structure, boundary conditions, etc., without actual data values. This is useful for testing and debugging applications.

