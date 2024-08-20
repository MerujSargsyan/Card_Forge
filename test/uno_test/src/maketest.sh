#!/bin/bash

CC="g++"
CFLAGS="-Wall -Wextra -std=c++11"
FORGESRC="../../../cardforge/src"
RAYDIR="../../../raylib/src"

$CC $CFLAGS -o uno_test uno_test.cpp -L$FORGESRC -I$FORGESRC -lcardforge -L$RAYDIR -I$RAYDIR -lraylib -framework Cocoa -framework IOKit -framework OpenGL
