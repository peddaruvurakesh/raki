#!/bin/bash

#author : Rakesh peddaruvu
#created date : 21/10/2024
#modified date: 21/10/2024



# Script Name: 164541_Rakesh_compress_files.sh
# Purpose: Compress all html, txt, and pdf files in a given directory and its subdirectories using gzip.

# Input: A directory path (/usr/share/doc)
# Output: Compressed files of html, txt, and pdf files are in the directory (/usr/share/doc)

# Check if a directory is given or not given
if [ -z "$1" ]; then
  echo "Error: No directory provided."
  echo "Usage: $0 <enter the directory>"
  exit 1
fi

# Check if the provided argument is a valid directory
if [ ! -d "$1" ]; then
  echo "Error: $1 is not a valid directory."
  exit 1
fi

# Compress all html, txt, and pdf files in the given directory and its subdirectories
find "$1" -type f \( -name "*.html" -o -name "*.txt" -o -name "*.pdf" \) -exec gzip {} \;

echo "Compression complete!"



