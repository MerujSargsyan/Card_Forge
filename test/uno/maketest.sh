#!/bin/bash

CC="g++"
CFLAGS="-Wall -Wextra -std=c++11"
FORGESRC="../../cardforge/"
RAYDIR="../../raylib/src"
BUILDIR="./build"

mkdir -p build

$CC -S $CFLAGS -c src/unolib.hpp -L$FORGESRC -I$FORGESRC $FORGESRC/cardforge.o -o $BUILDIR/unolib.o 

$CC $CFLAGS -o $BUILDIR/uno_test src/uno_test.cpp -I$BUILDIR $BUILDIR/unolib.o
