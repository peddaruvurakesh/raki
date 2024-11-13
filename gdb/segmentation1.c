#include <stdio.h>

int main() {
    int *ptr = NULL;  // Declare a pointer and set it to NULL
    *ptr = 42;        // Attempt to dereference the NULL pointer
    return 0;
}

