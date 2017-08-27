#include <stdio.h>
#include <cs50.h>

int main(void)
{
    printf("Height: ");
    int height = get_int();
    string start = "##";
    string hash = "#";
    int spaces = height - 1;
    string space = " ";
    // Rows
    for (int i = 0; i < height; i++) {
        // printf("%i\n", i);
        // printf("%s", space);
        for (int k = 0; k < spaces; k++) {
            printf("%s", space);
        }
        printf("%s", start);
        for (int j = 1; j <= i; j++) {
            printf("%s", hash);
        }
        printf("\n");
        spaces = spaces - 1;
        // Print stars
    }
    // printf("height: %i\n", height);
}