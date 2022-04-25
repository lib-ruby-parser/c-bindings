#!/usr/bin/env bash

set -eux

AR=$1
LIB=$2
OBJECTS_SEP_BY_SIME=$3

echo "AR = $AR"
echo "LIB = $LIB"
echo "OBJECTS_SEP_BY_SIME = $OBJECTS_SEP_BY_SIME"

IFS=";"
read -ra OBJECTS <<<"$OBJECTS_SEP_BY_SIME"

for item in "${OBJECTS[@]}";
do
    echo "Adding $item"
    if [ "$(basename $AR)" = "lib.exe" ]; then
        $AR "$LIB" "$item" /OUT:"$LIB"
    else
        $AR r "$LIB" "$item"
    fi
done
