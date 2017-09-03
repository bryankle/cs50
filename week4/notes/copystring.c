#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void) // Program does not require command line arguments
{

    printf("s: ");
    char *s = get_string(); // char *s is equivalent to string s. char *s stands for pointer to the character

    if (s == NULL) // If there is any error with string entered, ie: no memory
    {
        return 1;
    }

     char *t = malloc((strlen(s) + 1) * sizeof(char)); // Allocate memory to the size of letters for string s along with \0 to end
     if (t == NULL)
     {
         return 1;
     }

     for (int i = 0, n = strlen(s); i <= n; i++) // Copy each character from s to t
     {
         t[i] = s[i];
     }

     printf("s: %s\n", s);
     printf("t: %s\n", t);

     free(t); // Free allocated memory to prevent memory leaks

}