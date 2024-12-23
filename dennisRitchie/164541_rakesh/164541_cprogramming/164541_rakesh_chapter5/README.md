## Author
- **Gopi sai**
- **Created:** 5 Aug 2024
- **Modified:** 5 Aug 2024

# Tail command

Write the program tail, which prints the last n lines of its input. By default, n is set to 10, let us say, but it can be changed by an optional argument so that 
tail -n

## Table of Contents
- [Description](#description)
- [Features](#features)
- [Usage](#usage)
- [Example](#example)
- [Author](#author)

## Description
The program takes three inputs from the user:
1. Lower limit of the Celsius values (must be an integer).
2. Upper limit of the Celsius values (must be an integer).
3. Step size for the Celsius values (must be an integer).

Using these inputs, it generates a table converting the specified range of Celsius values to Fahrenheit. After displaying the table, the user is prompted to decide if they want to generate another table or exit the program.

## Features
- By default it print last 10 lines
- It can print last n lines
- It prints from given index to end of file.

## Usage
1. Compile the program using a C compiler, 
2. Run the compiled program
3. we can do tail command 

## Run the Program using MAKEFILE
1. Go to ROOT directory (cd CProgramming)
2. Run the below command.
3. make CFLAGS=164543_Gopi_chapter5/164543_Gopi_exercise5-13

## Example
./a.out 
./a.out -1
./a.out +2

