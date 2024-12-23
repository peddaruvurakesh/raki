#include <stdio.h>

// Space-efficient implementation of isupper
int isUpperSpace(char c) {
    return (c >= 'A' && c <= 'Z');
}

int main() {
    char testChar = 'A';

    if (isUpperSpace(testChar)) {
        printf("'%c' is uppercase (Space-Efficient Check)\n", testChar);
    } else {
        printf("'%c' is not uppercase (Space-Efficient Check)\n", testChar);
    }

    return 0;
}

