#!/bin/bash
git submodule update --init --recursive
cd ./raylib/src/ && make && cd -

CC="g++"
CFLAGS="-Wall -Wextra -std=c++11"
RAYDIR="./raylib/src/"
FORGDIR="./cardforge"

$CC $CFLAGS -c $FORGDIR/cardforge.cpp -o $FORGDIR/cardforge.o -L$RAYDIR -I$RAYDIR -lraylib -framework OpenGL -framework Cocoa -framework IOKit 
$CC $CFLAGS -c test/uno/src/unolib.cpp $FORGDIR/cardforge.o -o test/uno/build/unolib.o 
$CC $CFLAGS -o test/uno/build/uno_test test/uno/src/uno_test.cpp test/uno/build/unolib.o
