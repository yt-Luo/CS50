#include <stdio.h> // printf
#include <string.h> // strlen
#include <cs50.h> // get_string
#include <ctype.h> // isdigit, isupper, islower
#include <stdlib.h> // atoi

int main(int argc, string argv[])
{
    // Counting Command-Line Arguments & Validating the Key
    // check argc = 2, argv[0] = "./caesar ", argv[1] is digit
    if (argc != 2 || isdigit(*argv[1]) == false)
    {
        // If your program is executed without any command-line arguments or with more than one command-line argument
        // If any of the characters of the command-line argument is not a decimal digit
        // print the message Usage: ./caesar key and return from main a value of 1.
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        // atoi function converts a string argv[1] to int key for calculating ASCII code
        int k = atoi(argv[1]);

        // get plaintext
        string plaintext = get_string("plaintext: ");

        // output ciphertext: (without a newline)
        printf("ciphertext: ");

        // plaintext to cipertext
        for (int i = 0, n = strlen(plaintext); i < n; i++)
        {
            char ci, pi = plaintext[i];

            if (isupper(pi))
            {
                // ASCII value of A is 65.
                ci = ((pi - 65) + k) % 26 + 65;
            }
            else if (islower(pi))
            {
                // ASCII value of a is 97.
                ci = ((pi - 97) + k) % 26 + 97;
            }
            else
            {
                // non-alphabetical characters should be outputted unchanged.
                ci = pi;
            }
            printf("%c", ci);
        }
        // After outputting ciphertext, you should print a newline. Your program should then exit by returning 0 from main.
        printf("\n");
        return 0;
    }
}