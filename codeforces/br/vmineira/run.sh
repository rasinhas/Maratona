#!/bin/bash


g++ -o slow.o l2.cpp
g++ -o fast.o l.cpp
g++ -o gen.o zgen.cpp

if [ "$1" == "-n" ]; then
    ./gen.o > in
fi

f=`./fast.o < in`

s=`./slow.o < in`

echo $f
echo $s
if [ "$f" != "$s" ]; then
    cat in > err
    exit 0
fi
