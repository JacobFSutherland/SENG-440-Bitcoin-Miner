#!/bin/bash

set -e

cd src

folders=$(ls)

function nth_arg() {
    echo $1
}

args=""
for folder in $folders
do
    if [ -d $folder ]; then
        cd $folder
        make clean
        make release
        cd ..
        args="$args '$folder/main 16 0000000000000000000000000000000000000000000000000000000000000000 10'"
    fi
done

eval "hyperfine --warmup 3 $args"