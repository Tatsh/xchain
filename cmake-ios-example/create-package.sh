#!/bin/sh

echo "Based on http://theiphonewiki.com/wiki/index.php?title=HelloWorld_on_iPhone"
rm -fR build
mkdir build
cd build
cmake ..
make
cd ..
cp "build/CMakeExample" "CMake Example.app"
