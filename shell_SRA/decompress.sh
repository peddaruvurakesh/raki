#!/bin/bash

# Function to compress files using gzip
compress_files() {
  local dir="$1"
  
  # Find all files with .html, .txt, and .pdf extensions and compress them
  find "$dir" \( -name "*.html" -o -name "*.txt" -o -name "*.pdf" \) -type f | while read -r file; do
    if [ ! -f "$file.gz" ]; then
      echo "Compressing: $file"
      gzip "$file"
    else
      echo "Already compressed: $file"
    fi
  done
}

# Function to decompress files using gzip
decompress_files() {
  local dir="$1"
  
  # Find all files with .gz extension and decompress them
  find "$dir" -name "*.gz" -type f | while read -r file; do
    if [ -f "$file" ]; then
      echo "Decompressing: $file"
      gunzip "$file"
    else
      echo "File not found for decompression: $file"
    fi
  done
}

# Check if the directory argument is provided
if [ -z "$1" ]; then
  echo "Usage: $0 <directory> [compress|decompress]"
  exit 1
fi

# Check if the second argument is provided (compress or decompress)
if [ -z "$2" ]; then
  echo "Specify operation: compress or decompress"
  exit 1
fi

# Perform compression or decompression based on the second argument
if [ "$2" == "compress" ]; then
  compress_files "$1"
elif [ "$2" == "decompress" ]; then
  decompress_files "$1"
else
  echo "Invalid operation. Use 'compress' or 'decompress'."
  exit 1
fi

