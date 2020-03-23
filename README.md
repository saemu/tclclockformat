
# Tcl Demo Application

## Introduction
The Demo Application to show Tcl command `clock format` is not working as expected,
when using Tcl as library in a C++ Application.

## How to Build
### Requirements
* C++ Development Environment with support for C++14 or newer
* CMake v3.15 or newer
* Ninja Build System
* Python

### Instructions
```shell
pip install --user --upgrade conan
conan user
mkdir build
cd build
conan install .. --build=missing
cmake .. -G Ninja
cmake --build . --target all
```
