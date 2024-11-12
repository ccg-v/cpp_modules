#!/bin/bash
# Set 'MAX' with the amount of numbers to be sorted
# To run: ./tester.sh

MAX=3000
NUMS=$(shuf -i 1-$MAX | tr '\n' ' ')

echo "Generated sequence: $NUMS"
./a.out $NUMS | wc -l