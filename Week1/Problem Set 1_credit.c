#include <stdio.h>  // printf
#include <cs50.h> //get_long

int main(void)
{

    long n;

    // run once and go to next step when n > 0
    do
    {
        //Enter crdeit card number
        n = get_long("Nunber: ");

    }
    while (n < 0);

    int checksum = 0, length = 0, digit, digit1;

    for (long i = n ; i > 0; i /= 100)
    {
        digit = i % 10;
        checksum += digit;
        length += 1;

        if (i / 10 > 0)
        {
            digit1 = i / 10 % 10;
            if (digit1 * 2 > 9)
            {
                checksum += digit1 * 2 - 9;
            }
            else
            {
                checksum += digit1 * 2;
            }
            length += 1;

        }
        //printf("%li %i %i %i %i\n", i,digit, digit1,checksum, length);  //for test

    }

    //legal if the last digit in that sum is 0
    if (checksum % 10 == 0)
    {
        // check AMEX (15 digits, start with 34 or 37)
        if (length == 15 && digit == 3 && (digit1 == 4 || digit1 == 7))
        {
            printf("AMEX\n");
        }
        //check MASTERCARD (16 digits, start with 51,51,53,54,55)
        else if (length == 16 && digit1 == 5 && digit > 0 && digit < 6)
        {
            printf("MASTERCARD\n");
        }
        //check VISA (13 or 16 digits, start with 4)
        else if ((digit == 4 && length == 13) || (length == 16 && digit1 == 4))
        {
            printf("VISA\n");
        }

        else
        {
            printf("INVALID\n");
        }
    }
    //invalid if the last digit in that sum is not 0
    else
    {
        printf("INVALID\n");
    }
}