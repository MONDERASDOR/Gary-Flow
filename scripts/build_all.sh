#!/bin/bash
set -e
cmake -S .. -B ../build && cmake --build ../build
cd ../java && mvn package
