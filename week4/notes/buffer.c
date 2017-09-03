#include <string.h>
#include <stdio.h>

void foo(char *bar) // Function that accepts pointer bar
{
    char c[12]; // Creates space for 12 characters (array for characters as opposed to integers)
    memcpy(c, bar, strlen(bar)); // memcpy accepts 3 arguments, target to copy to, source to copy from, and space allocated for copy)
}

int main(int argc, char *argv[])
{
    if (argc == 2) // Only executes function if 1 command line argument is included
    {
        foo(argv[1]);
    }
}

// Buffer overflow occurs when an argument of string greater than 12 characters is added. When this occurs, the additional characters
// will overwrite data 