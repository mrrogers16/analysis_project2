#!/bin/bash

if [$# -ne 1 ]; then
    echo "Usage: bash project2.sh controlfile.txt"
    exit 1
fi

CONTROL_FILE=$1

make clean
make
./project2 "$CONTROL_FILE"