#!/bin/sh

mkdir build
cd build

OPTIND=1         # Reset in case getopts has been used previously in the shell.

cmaketype="DEBUG"

while getopts dr opt; do
    case "$opt" in
    d)  cmaketype="DEBUG"
        ;;
    r)  cmaketype="RELWITHDEBINFO"
        ;;
    esac
done

shift $((OPTIND-1))

echo "Build type is ${cmaketype}"
cmake -DCMAKE_BUILD_TYPE=${cmaketype} ..
