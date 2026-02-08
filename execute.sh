#!/usr/bin/env bash

# stop if compiling fail
# -e: errorexit - exit immediately on error
# -u: nounset - error on unset variable
# -o pipefaul: fail pipelines correctly
set -euo pipefail

# create directory if it does not exist
if [[ ! -d "./build" ]]; then
  mkdir build
fi

# remove build file for clean build
if [[ -f "./build/main.exe" ]]; then
  rm -f ./build/main.exe
fi

# compile
c++ ./src/main.cpp -o ./build/main.exe

# run executable
./build/main.exe
