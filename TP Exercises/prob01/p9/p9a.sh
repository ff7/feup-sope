#!/bin/bash
if [[ !  $# -eq 1 ]]
then
    echo "Wrong number of arguments"
    exit 1
fi

rm "$1" 
rm "$1.o"

FILE="$1.c"
gcc -Wall -o $1 $FILE
./$1
