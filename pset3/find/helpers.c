/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */

#include <cs50.h>

#include "helpers.h"
#include <stdio.h>
#include <math.h>
/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    printf("%s\n", "Searching...");
    // TODO: implement a searching algorithm
    int mid = values[(n - 1)/ 2];
    // Check first if mid value is equal to searched value
        // If match, return true
    printf("%s%d\n", "Value: ", value);
    printf("%s%d\n", "Mid Point: ", mid);
    printf("%s%d\n", "Size: ", n);
    if (value == mid)
    {
        return 1;
    }
    else if (n == 2)
    {
        if (values[0] == value || values[1] == value)
        {
            printf("%s\n", "Found22!");
            return 1;
        }
    }

    else if (n == 1 && value != mid)
    {
        printf("%s\n", "n == 1 && value != mid");
        return 1;
    }
    // If search value is greater than mid value, search greater half
    else if (value > mid)
    {
        int greaterSize = n - (n / 2);
        printf("%s%d\n", "greaterSize: ", greaterSize);
        int greaterArr[greaterSize];
        for (int i = greaterSize, j = 0; i < n; i++, j++)
        {
            greaterArr[j] = values[i];
        }
        // Print out greaterArr
        printf("%s\n", "Larger half of array");
        for (int i = 0; i < greaterSize; i++)
        {
            printf("%d\n", greaterArr[i]);
        }
        return search(value, greaterArr, greaterSize);
    }

    // If search value is less than mid value, search lesser half
    else if (value < mid)
    {
        // printf("%s\n", "Smaller half of array");
        int lesserSize = (n - 1) / 2;
        int lesserArr[lesserSize];
        for (int i = 0; i < lesserSize; i++)
        {
            lesserArr[i] = values[i];
        }
        printf("%s\n", "Smaller half of array");
        for (int i = 0; i < lesserSize; i++)
        {
            printf("%d\n", lesserArr[i]);
        }
        return search(value, lesserArr, lesserSize);
    }
    return 0;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    bool swap = true;
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", values[i]);
    }

    printf("%s\n", "Sorting...");

    while(swap)
    {
        swap = false;
        for (int i = 0; i < n - 1; i++)
        {
            if (values[i + 1] < values[i])
            {
                swap = true;
                int temp = values[i + 1];
                values[i + 1] = values[i];
                values[i] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", values[i]);
    }

    return;
}
