#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // get line of text
    char *s = get_string();
    if (s == NULL)
    {
        return 1;
    }

    // print string, one character a time
    for (int i = 0, n = strlen(s); i < n; i++) // Loops through each memory block
    {
        printf("%c\n", *(s + i)); // Points to each individual subsequent character with each iteration
    }
}