#!/bin/bash
git submodule update --init --recursive

cd ./raylib/src/ && make && cd -
cd ./cardforge/src/ && ./makelib.sh
