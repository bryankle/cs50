#include <cs50.h>
#include <stdio.h>
#include <string.h>


int main(int argc, string argv[])
{
    // Ensure that the command line input only contains 1 word

    if (argc == 2) {
        string k = argv[1]; // abc
        printf("%s", "plaintext: ");
        string p = get_string(); // hello
        // Loop through k to assign corrected Vigenere cipher
        printf("%s", "ciphertext: ");
        for (int i = 0, j = 0; i < strlen(p); i++)
        {
            // i loops over plaintext p
            // j counter to loop over command line argument k
            // Reset j to 0 when it reaches max length to loop from beginning
            if (j == strlen(k))
            {
                j = 0;
            }
            // If uppercase
            int charCode = p[i];
            int vig = k[j];

            if ((charCode >= 65 && charCode <= 90) || (charCode >= 97 && charCode <= 122))
            {

                if (vig >= 65 && vig <= 90)
                {
                    vig = vig - 65;
                }
                // If lowercase
                else if(vig >= 97 && vig <= 122)
                {
                    vig = vig - 97;
                }

                int newCharCode = charCode + vig;
                if (newCharCode > 122)
                {
                    newCharCode = newCharCode - 122 + 97 - 1;
                }
                else if (newCharCode > 90 && newCharCode < 97)
                {
                    newCharCode = newCharCode - 90 + 65 - 1;
                }
                printf("%c", (char) newCharCode);
                j++;
            }
            else if (charCode >= 48 && charCode <= 57)
            {
                return 1;
            }
            else
            {
                printf("%c",  p[i]);
            }

        }
    }
    else
    {
        printf("%s\n", "Usage: ./vigenere k");
        return 1;
    }
    printf("\n");
}

