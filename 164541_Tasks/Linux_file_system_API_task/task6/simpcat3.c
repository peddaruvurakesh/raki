#include <stdio.h>  

// Main function
int main() {
  char c;  // Declare a character variable to hold the input
  int i;   // Declare an integer to hold the result of the fread call

  i = fread(&c, 1, 1, stdin);  // Read 1 byte from stdin and store it in 'c'
  while (i > 0) {  
    fwrite(&c, 1, 1, stdout);  // Write 1 byte to stdout
    i = fread(&c, 1, 1, stdin);  // Read the next byte from stdin
  }
}

