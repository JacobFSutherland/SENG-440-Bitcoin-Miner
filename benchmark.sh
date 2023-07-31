#!/bin/bash

set -e

cd src

folders=$(ls)

args=""
for folder in $folders
do
    if [ -d $folder ]; then
        cd $folder
        make clean
        make release
        cd ..
        args="$args '$folder/main 16 0000000000000000000000000000000000000000000000000000000000000001 10'"
    fi
done

eval "hyperfine --warmup 5 $args"