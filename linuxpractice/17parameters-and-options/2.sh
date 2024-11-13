#!/bin/bash

if [ $# -ne 2 ]; then
	echo "usage $0 give only 2 arguements"
	exit 1
fi
file1=$1
file2=$2
if [ -e "$file1" ]; then
	echo "$file1 exists"
       else
    echo "$file1 does not exist."
fi

if [ -e "$file2" ]; then
    echo "$file2 exists."
else
    echo "$file2 does not exist."
fi
