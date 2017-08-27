#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    int counter = 0;


    printf("Change: ");
    float change = get_float();
    // printf("%d\n", change);
    // printf("%f\n", quarter);
    while (change > 0) {
        // printf("%f\n", change);
        counter++;
        if (change >= 0.25) {
            change = round(change - 0.25);
        }
        else if (change >= 0.10) {
            change = round(change - 0.10);
        }
        else if (change >= 0.05) {
            change = round(change - 0.05);
        }
        else {
            change = round(change - 0.01);
        }
        printf("%f\n", change);
    }
    printf("%d\n", counter);
}