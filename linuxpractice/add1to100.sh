#!/bin/bash

read -p "Enter a number (1-100): " num1
if ((num1 < 1 || num1 > 100)); then
    echo "Error: Number must be between 1 and 100."
    exit 1
fi

read -p "Enter another number (1-100): " num2
if ((num2 < 1 || num2 > 100)); then
    echo "Error: Number must be between 1 and 100."
    exit 1
fi

sum=$((num1 + num2))
product=$((num1 * num2))

echo "Sum: $num1 + $num2 = $sum"
echo "Product: $num1 x $num2 = $product"

