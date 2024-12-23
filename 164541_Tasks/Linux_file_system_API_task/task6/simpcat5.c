#include <stdio.h>    
#include <stdlib.h>  

//extern char *malloc(int);  // Declare malloc function to allocate memory

int main(int argc, char **argv) {
  int bufsize;  // Buffer size from command line argument
  char *c;      // Pointer to the buffer
  int i;        // Number of bytes read

  bufsize = atoi(argv[1]);  // Convert argument to integer (buffer size)
  c = malloc(bufsize);      // Allocate memory for the buffer

  i = 1;  
  while (i > 0) {
    i = fread(c, 1, bufsize, stdin);  // Read bufsize bytes from stdin
    if (i > 0) fwrite(c, 1, i, stdout);  // Write i bytes to stdout if data was read
  }
}

