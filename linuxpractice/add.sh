#!/bin/bash

read -p "Enter a number: " num1
read -p "Enter another number: " num2

sum=$((num1 + num2))
product=$((num1 * num2))

echo sum "$sum"
echo product "$product"

