#!/bin/bash

CC="g++"
CFLAGS="-Wall -Wextra"
FORGESRC="../../../cardforge/src"

$CC $CFLAGS -o uno_test uno_test.cpp -L$FORGESRC -I$FORGESRC -lcardforge
