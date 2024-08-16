#!/bin/zsh

gcc -o main main.cpp -lglfw -L../build/_deps/ -framework Cocoa -framework OpenGL -framework IOKit
