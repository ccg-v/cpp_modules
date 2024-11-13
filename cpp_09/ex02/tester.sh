#!/bin/bash
# Set 'MAX' with the amount of numbers to be sorted
# To run: ./tester.sh

MAX=20
NUMS=$(shuf -i 1-$MAX | tr '\n' ' ')

echo "Generated sequence: $NUMS"
./PmergeMe $NUMS | wc -l