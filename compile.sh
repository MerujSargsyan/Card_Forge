#!/bin/bash

CC="gcc"
CFLAGS="-Wall -Wextra -std=c99"
RAYDIR="raylib/src"
FORGDIR="cardforge/src"

git submodule update --init --recursive
cd ./raylib/src && make
cd ../../
pwd

if [[ "$OSTYPE" == "darwin"* ]]; then
    $CC $CFLAGS -o main src/main.c -I$RAYDIR -L$RAYDIR -lraylib -framework OpenGL -framework Cocoa -framework IOKit -I$FORGDIR -L$FORGDIR -lcardforge
else
    $CC $CFLAGS -o main main.c -I$RAYDIR -L$RAYDIR -lraylib -I$FORGDIR -L$FORGDIR -lcardforge
fi
