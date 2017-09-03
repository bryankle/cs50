#include <cs50.h>
#include <stdio.h>
#include <string.h>

#include "structs.h" // Imports file structs.h; similar to a schema

#define STUDENTS 3 // Define a "STUDENTS" constant to 3, cannot be redefined

int main(void)
{
    student students[STUDENTS]; // Declare an array "students" to contain 3 elements

    for (int i = 0; i < STUDENTS; i++)
    {
        printf("name: ");
        students[i].name = get_string();

        printf("dorm: ");
        students[i].dorm = get_string();
    }
    // Prints out names and dorms of students

    // for (int i = 0; i < STUDENTS; i++)
    // {
    //     printf("%s is in %s.\n", students[i].name, students[i].dorm);
    // }

    FILE *file = fopen("students.csv", "w"); // Pointer to refer to file location. 'w' writes in file "students.csv". Creates a new file if not already existing
    if (file != NULL)
    {
        for (int i = 0; i < STUDENTS; i++)
        {
            fprintf(file, "%s,%s\n", students[i].name, students[i].dorm);
        }
        fclose(file); // Close file once completed
    }

}
// Similar to JSON
/*
    var students = [
        {
            name: 'Bryan',
            dorm: 'Livingston'
        },
        ...
    ]

*/