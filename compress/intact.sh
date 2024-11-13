#!/bin/bash

#author : Rakesh Peddaruvu
#created date : 21/10/2024
#modified date: 21/10/2024

# Script Name: 164541_Rakesh_compress_files.sh
# Purpose: Compress all html, txt, and pdf files in a given directory and its subdirectories using gzip.
#          The original files will be kept intact, and new .gz files will be created.

# Input: A directory path (/usr/share/doc)
# Output: Compressed .gz files of html, txt, and pdf files are created in the directory, with original files intact.

# Check if a directory is given
if [ -z "$1" ]; then
  echo "Error: No directory provided."
  echo "Usage: $0 <directory>"
  exit 1
fi

# Check if the provided argument is a valid directory
if [ ! -d "$1" ]; then
  echo "Error: $1 is not a valid directory."
  exit 1
fi
#create directory
if [ ! -d "$2" ]; then
  echo "Output directory does not exist. Creating directory: $2"
  mkdir -p "$2"
fi


# Compress all html, txt, and pdf files in the given directory and its subdirectories,
# keeping the original files intact by using the -c option for gzip.
find "$1" -type f \( -name "*.html" -o -name "*.txt" -o -name "*.pdf" \) -exec sh -c '
  for file; do
    gzip -c "$file" > "$file.gz"
  done
' sh {} "$2"+

echo "Compression complete! Original files are intact, and .gz files have been created."

