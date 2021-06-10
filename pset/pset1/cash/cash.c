#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    // TODO: Prompt for input
    float owe = 0;
    while (owe <= 0)
    {
        owe = get_float("Change owed: ");
    }

    //round
    int cents = round(owe * 100);

    //coin counter
    int coin = 0;

    //while loop for coins
    while (cents >= 25) //quater
    {
        cents = cents - 25;
        coin++;
    }

    while (cents >= 10) //dime
    {
        cents = cents - 10;
        coin++;
    }

    while (cents >= 5) //nickel
    {
        cents = cents - 5;
        coin++;
    }
    while (cents >= 1) //penny
    {
        cents = cents - 1;
        coin++;
    }

    printf("Cash : %i\n", coin);

}