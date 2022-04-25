#!/usr/bin/env bash

set -eux

AR=$1
LIB=$2
OBJECTS=$3

echo "AR = $AR"
echo "LIB = $LIB"
echo "OBJECTS = $OBJECTS"

OBJECTS=$(echo "$OBJECTS" | sed "s/;/ /g")
echo "Adding $OBJECTS"

if [ "$AR" = "lib.exe" ]; then
    lib.exe "$LIB" "$OBJECTS" /OUT:"$LIB"
else
    $AR r "$LIB" "$OBJECTS"
fi
