#include <unistd.h> 

// Main function
int main() {
  char c;  // Declare a character variable to hold the input
  int i;   // Declare an integer to hold the result of the read call

  i = read(0, &c, 1);  // Read 1 byte from file descriptor 0 (stdin), store it in 'c'
  while (i > 0) {  
    write(1, &c, 1);  // Write 1 byte to file descriptor 1 (stdout)
    i = read(0, &c, 1);  // Read the next byte from stdin
  }
}

