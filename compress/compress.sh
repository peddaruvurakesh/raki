#!/bin/bash

# Check if two arguments are provided
if [ "$#" -ne 2 ]; then
    echo "Usage: $0 <source_directory> <output_directory>"
    exit 1
fi

SOURCE_DIR="$1"
OUTPUT_DIR="$2"

# Create the output directory
mkdir -p "$OUTPUT_DIR"

# Compress files and move them to the output directory
find "$SOURCE_DIR" -type f \( -name "*.html" -o -name "*.txt" -o -name "*.pdf" \) -exec bash -c 'gzip -c "$1" > "$2/$(basename "$1").gz"' _ {} "$OUTPUT_DIR" \;

echo "Compression complete. Compressed files are in: $OUTPUT_DIR"

