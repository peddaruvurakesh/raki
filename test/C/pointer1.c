#include <stdio.h>

int main() {
    int a, b = 5;
    a = b + (int)NULL;  // Typecast NULL to int
    printf("%d", a);
    return 0;
}

