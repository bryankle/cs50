#include <stdlib.h>

void f(void) // Function
{
    int *x = malloc(10 * sizeof(int)); // Allocates memory space for 10 integers (array)
    x[10] = 0; // Referencing non-existent place in memory space 'x'
    // free(x);
}

int main(void)
{
    f();
    return 0;
}