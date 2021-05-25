#include <stdio.h> // printf
#include <cs50.h> // get_string
#include <ctype.h>  // isalpha, tolower, toupper
#include <string.h> // strlen

int substitution(string key);  // declare substitution

int main(int argc, string argv[])
{
    // check if argc = 2
    if (argc != 2)
    {
        // print an error message of your choice (with printf) and return from main a value of 1 immediately.
        printf("Usage: ./substitution key\n");
        return 1;
    }
    // check if the key is 26 characters
    else if (strlen(argv[1]) != 26)
    {
        // print an error message of your choice (with printf) and return from main a value of 1 immediately.
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    // check if the key is valid
    else
    {
        for (int i = 0; i < 26; i++)
        {
            // check if the key containing only alphabetic character
            if (isalpha(argv[1][i]) == false)
            {
                //print an error message of your choice (with printf) and return from main a value of 1 immediately.
                printf("Key must only contain alphabetic characters.\n");
                return 1;
            }
            else
            {
                // check if the key containing each letter exactly once
                for (int j = i; j < 25; j++)
                {
                    if (tolower(argv[1][i]) == tolower(argv[1][j + 1]))
                    {
                        // print an error message of your choice (with printf) and return from main a value of 1 immediately.
                        printf("Key must not contain reapeated characters.\n");
                        return 1;
                    }
                }
            }

        }
        // do substitution
        substitution(argv[1]);
    }
}

int substitution(string key)
{
    // get plaintext
    string plaintext = get_string("plaintext: ");

    // output ciphertext: (without a newline)
    printf("ciphertext: ");

    // plaintext to cipertext
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        char c, p = plaintext[i];

        if (isupper(p))
        {
            // change 'A'-'Z' to key[0]-key[25], 'B' = 'A' + 1, 'C' = 'A' + 2 ...
            // toupper: capitalized letters must remain capitalized letters
            c = toupper(key[p - 'A']);
        }
        else if (islower(p))
        {
            // change 'a'-'z' to key[0]-key[25], 'b' = 'z' + 1, 'c' = 'a' + 2 ...
            // tolower: lowercase letters must remain lowercase letters.
            c = tolower(key[p - 'a']);
        }
        else
        {
            // non-alphabetical characters should be outputted unchanged.
            c = p;
        }
        // print ciphertext
        printf("%c", c);
    }
    // After outputting ciphertext, you should print a newline. Your program should then exit by returning 0 from main.
    printf("\n");
    return 0;
}
