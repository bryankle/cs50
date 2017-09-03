#include <stdio.h>

void swap(int *a, int *b); // Hoisting function 'swap' for program to reference. Swap accepts 2 pointers


int main(void)
{
    int x = 1;
    int y = 2;

    printf("x is %i\n", x);
    printf("y is %i\n", y);
    printf("Swapping...\n");
    swap(&x, &y); // What does '&' do in this case? Pointer reference?
                // '&' is used to get the address of a variable
                // '*' can be used to get the address given by '&'
    printf("Swapped!\n");
    printf("x is %i\n", x);
    printf("y is %i\n", y);

}

void swap(int *a, int *b) // * is used to get the value of given address
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}