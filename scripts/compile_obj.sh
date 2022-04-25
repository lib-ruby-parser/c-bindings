#!/usr/bin/env bash

set -eux

CC=$1
CFLAGS=$2
INPUTS=$3
OUTPUT=$4

echo "CC = $CC"
echo "CFLAGS = $CFLAGS"
echo "INPUTS = $INPUTS"
echo "OUTPUT = $OUTPUT"

if [ "$(basename \"$CC\")" = "cl.exe" ]; then
    # MSVC
    "$CC" $CFLAGS $INPUTS /link /OUT:$OUTPUT
else
    # Clang/GCC/MinGW
    "$CC" $CFLAGS $INPUTS -o $OUTPUT
fi
