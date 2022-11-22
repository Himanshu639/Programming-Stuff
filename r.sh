#! /usr/bin/bash

echo $(clear)
echo $(g++ $1.cpp -o $1)
echo $(./$1.exe)
echo $(rm $1.exe)
