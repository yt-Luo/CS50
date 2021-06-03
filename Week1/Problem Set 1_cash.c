#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float dollars;
    int cents, coins = 0;

    // run once and go to next step when n > 0
    do
    {
        //Enter change owned
        dollars = get_float("Change owned: ");
        cents = round(dollars * 100);
    }
    while (cents < 0);

    // use quarters
    while (cents - 25 >= 0)
    {
        coins++;
        cents -= 25;
    }

    //use dimes
    while (cents - 10 >= 0)
    {
        coins++;
        cents -= 10;
    }

    // use nickels
    while (cents - 5 >= 0)
    {
        coins++;
        cents -= 5;
    }

    //use pennies
    coins += cents;

    printf("%i\n", coins);
}