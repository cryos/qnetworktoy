Toy C++/Qt Network Client
=========================

Intended to get familiar with newer syntax, offer a simple test client where
the type can be specified. Very fragile, and probably not useful to you...

Building
--------

This project uses CMake 3.1+ and Qt 5 along with C++14. The simplest way to
clone and build the project if you have the requirements is:

    git clone git://github.com/cryos/qnetworktoy
    cd qnetworktoy
    cmake -S . -B build
    cmake --build build

Using
-----

You can run the binary from the source tree location above:

    ./build/qnetworktoy
