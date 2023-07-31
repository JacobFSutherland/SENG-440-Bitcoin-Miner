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

    # folder != "simd" || folder != "naive-o3"
    if [ -d $folder ] && [ $folder != "simd" ] && [ $folder != "naive-o3" ]; then
        cd $folder
        make clean
        make release-opt
        cd ..
        args="$args '$folder/main 16 0000000000000000000000000000000000000000000000000000000000000001 10'"
    fi
done

eval "hyperfine --warmup 5 $args"