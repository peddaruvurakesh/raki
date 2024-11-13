#!/bin/bash

shopt -s nocasematch  # Enable case-insensitive matching

read -p "Enter a color (red, green, blue): " color

case $color in
    red) 
        echo "You chose red!" 
        ;;
    green) 
        echo "You chose green!" 
        ;;
    blue) 
        echo "You chose blue!" 
        ;;
    *) 
        echo "Unknown color." 
        ;;
esac

shopt -u nocasematch  # Disable case-insensitive matching

