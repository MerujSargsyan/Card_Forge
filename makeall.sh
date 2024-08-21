#!/bin/bash

cd ./raylib/src/ && make && cd -
cd ./cardforge/src/ && ./makelib.sh
