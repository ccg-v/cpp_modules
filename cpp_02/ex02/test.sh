#!/bin/bash

# Before running copy the expected output from the subject to
# a new file called 'expected_output'. 
# Don't forget checking the content is copied with the proper
# indentation!

# Check if 'expected_output.txt' exists
if [ ! -e "expected_output.txt" ]; then
    echo "Error: 'expected_output.txt' not found"
    exit 1
fi

./fixed.out > test_output.log
# Compare the test output with the provided logs using diff
diff test_output.log expected_output.txt

# Check the exit code of diff
if [ $? -eq 0 ]; then
	echo -e "\033[0;32mPASSED\033[0m"	# print PASSED in green
else
	echo -e "\033[0;31mFAILED\033[0m"   # Print FAILED in red
fi
