#!/bin/sh
./map.py
make
getData
echo "verify accuracy by counting line numbers:"
echo "locations.txt"
cat locations.txt | wc -l
getData | wc -l
