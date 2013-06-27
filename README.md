cxx11-samples
=============

A set of new C++11 samples

Prerequisites
gyp - run 'svn checkout http://gyp.googlecode.com/svn/trunk build/gyp' from root of the project

clang3.3 - get from http://www.llvm.org/releases/download.html#3.3

libC++ library - get from http://www.llvm.org/releases/3.3/libcxx-3.3.src.tar.gz

How to generate project files for make:
./build/gyp/gyp -f make --depth . auto.gyp

How to build:
make

How to run:
./out/Default/auto