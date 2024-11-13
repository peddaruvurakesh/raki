#!/bin/bash

# Find and delete all files with .Identifier extension
find . -type f -name "*.Identifier" -exec rm -f {} \;

echo "All *.Identifier files have been deleted."

