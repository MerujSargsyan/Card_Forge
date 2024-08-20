#!/bin/bash

CC="g++"
CFLAGS="-Wall -Wextra -std=c++11"
FORGESRC="../../cardforge/src"
RAYDIR="../../raylib/src"
BUILDIR="./build"

$CC $CFLAGS -o $BUILDIR/uno_test src/uno_test.cpp -L$FORGESRC -I$FORGESRC -lcardforge -L$RAYDIR -I$RAYDIR -lraylib -framework Cocoa -framework IOKit -framework OpenGL
