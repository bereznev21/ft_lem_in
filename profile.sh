#!/bin/bash

MAP=maps/generated/big-superposition1.map
rm -f callgrind.out.*
valgrind --tool=callgrind ./lem-in <$MAP
callgrind_annotate --auto=yes callgrind.out.* > profiling.txt
