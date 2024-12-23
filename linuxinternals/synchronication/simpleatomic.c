#include <stdio.h>
#include <stdatomic.h>
 
int main()
{
    atomic_int counter = 0;  // Declare an atomic integer
    atomic_fetch_add(&counter, 3);  // Atomically increment the counter by 1
    printf("Counter: %d\n", counter);  // Print the final value of the counter
    return 0;
}
