#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n, i, j, k;

    // run once and continue when n = 1~8
    do
    {
        //Enter height
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);

    //row by row
    for (i = 0; i < n; i++)
    {
        //print space*n-1-i
        for (j = n - i; j > 1 ; j--)
        {
            printf(" ");
        }

        //print # *i
        for (k = 0; k <= i; k++)
        {
            printf("#");
        }

        //print gap
        printf("  ");

        //print right hashs
        for (k = 0; k <= i; k++)
        {
            printf("#");
        }

        //new line, next row
        printf("\n");
    }

}