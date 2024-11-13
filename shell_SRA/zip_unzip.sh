#!/bin/bash

# Check if a directory is given or not
if [ -z "$1" ]; then
  echo "Error: No directory provided."
  echo "Usage: $0 <directory> <compress|decompress>"
  exit 1
fi

# Check if the provided argument is a valid directory
if [ ! -d "$1" ]; then
  echo "Error: $1 is not a valid directory."
  exit 1
fi

# Check if the second argument (operation) is provided
if [ -z "$2" ]; then
  echo "Error: No operation provided."
  echo "Usage: $0 <directory> <compress|decompress>"
  exit 1
fi

# Perform compression or decompression based on the second argument
if [ "$2" == "compress" ]; then
  # Compress all html, txt, and pdf files in the given directory and its subdirectories
  find "$1" -type f \( -name "*.html" -o -name "*.txt" -o -name "*.pdf" \) -exec gzip {} \;
  echo "Compression complete!"
  
elif [ "$2" == "decompress" ]; then
  # Decompress all .gz files in the given directory and its subdirectories
  find "$1" -type f -name "*.gz" -exec gunzip {} \;
  echo "Decompression complete!"
  
else
  # If the second argument is neither 'compress' nor 'decompress', print an error
  echo "Error: Invalid operation. Use 'compress' or 'decompress'."
  exit 1
fi

