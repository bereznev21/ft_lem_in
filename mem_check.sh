#!/bin/bash

MAP=maps/generated/big-superposition1.map
make
valgrind --leak-check=full ./lem-in $MAP
