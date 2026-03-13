#!/bin/bash

rm ./pathFinder

if gcc -Wall -pedantic -o pathFinder main.c -lraylib -lGL -lm -lpthread -ldl -lrt -lX11; then
  echo compiled
else
  exit $?
fi

if test "$1" != check ; then
  ./pathFinder
fi
