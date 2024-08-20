#!/bin/bash

CC="g++"
CFLAGS="-Wall -Wextra -std=c++11"
RAYDIR="../../raylib/src"

$CC $CFLAGS -c cardforge.cpp -I$RAYDIR -L$RAYDIR -lraylib -framework Cocoa -framework IOKit -framework OpenGL -o cardforge.o
ar rcs libcardforge.a cardforge.o 
