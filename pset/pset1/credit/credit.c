#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    // TODO: Prompt for input
    long cardN = 0;
    while (cardN <= 0)
    {
        cardN = get_long("Number: ");
    }

    long n = cardN; // just to keep cardN debug

    int counter = 0; //for legth
    int csum = 0; //cheksumn
    int sum = 0; //allsum
    int firstDigit = 0; // for cardtype

    while (n > 1)
    {
        //last digit
        csum = n % 10; //last digit
        sum = csum + sum; //store cheksum to sum

        if (n > 0) // counter
        {
            counter++;
        }

        n = n / 10;

        if (n > 10) // store first digit
        {
            firstDigit = round(n);
        }

        //last digit -1
        csum = (n % 10) * 2; //last digit
        if (csum > 9)
        {
            csum = csum - 9; //-9 if digit > 9
        }
        sum = csum + sum; //store cheksum to sum

        if (n > 0) // counter
        {
            counter++;
        }
        n = n / 10;

        if (n > 10) // store first digit
        {
            firstDigit = round(n);
        }
    }


    // sort cards
    if (sum % 10 != 0)
    {
        printf("INVALID\n");
    }
    else if ((firstDigit == 34 || firstDigit == 37) && counter == 15)
    {
        printf("AMEX\n");
    }
    else if ((firstDigit > 39 && firstDigit < 50) && (counter == 13 || counter == 16))
    {
        printf("VISA\n");
    }
    else if ((firstDigit > 50 && firstDigit < 56) && counter == 16)
    {
        printf("MASTERCARD\n");
    }
    else
    {
        printf("INVALID\n");
    }

}