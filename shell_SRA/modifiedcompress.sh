#!/bin/bash

# Check if a directory argument is provided
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

# Function to compress files by extension in a given directory
compress_by_extension() {
  local dir="$1"
  local ext="$2"

  # Find files with the specified extension in the current directory
  files=$(find "$dir" -maxdepth 1 -type f -name "*.$ext")
  
  # If files are found, compress them into a single archive
  if [ -n "$files" ]; then
    tar -czf "$dir/${ext}_files.tar.gz" $files
    echo "Compressed $ext files in $dir to ${ext}_files.tar.gz"
    # Optionally, delete original files after compression
    # Uncomment the line below to enable deletion
    # rm $files
  fi
}

# Export the function for use with find
export -f compress_by_extension

# Iterate through all directories and compress files
find "$1" -type d | while read -r dir; do
  # Compress .txt files
  compress_by_extension "$dir" "txt"
  # Compress .html files
  compress_by_extension "$dir" "html"
  # Compress .pdf files
  compress_by_extension "$dir" "pdf"
done

echo "All files have been compressed."

