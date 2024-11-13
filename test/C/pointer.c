#include <stdio.h>

int main() {
    unsigned int i = 255;
    float a = 2;
    char *ii, *aa;
    
    ii = (char *)&i;
    aa = (char *)&a;
    
    printf("Address contained in ii = %p\n", ii);
    printf("Address contained in aa = %p\n", aa);
    printf("Value at the address contained in ii = %d\n", *ii);
    printf("Value at the address contained in aa = %d\n", *aa);
    
    return 0;
}

