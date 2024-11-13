#!/bin/bash

# Check if exactly four parameters are provided
if [ "$#" -ne 4 ]; then
  echo "Usage: $0 param1 param2 param3 param4"
  exit 1
fi
