#!/bin/bash

set -e

cd src

folders=$(ls)

for folder in $folders
do
    if [ -d $folder ]; then
        cd $folder
        echo "=== Testing $folder ==="
        make clean
        make release
        ./test_main.sh
        ./test_sha256.sh
        cd ..
    fi
done