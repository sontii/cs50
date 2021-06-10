#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int startSize = 0;
    while (startSize <= 8)
    {
        startSize = get_int("Start size: ");
    }


    // TODO: Prompt for end size
    int endSize = 0;
    while (endSize < startSize)
    {
        endSize = get_int("End size: ");
    }

    // TODO: Calculate number of years until we reach threshold

    int year = 0;

    // check befor calc
    if (startSize == endSize)
    {
        printf("Years: %i\n", year);
    }

    else
    {

        //Loop for yearly population
        for (int n = 0; startSize < endSize;)
        {
            startSize = startSize + (startSize / 3) - (startSize / 4);
            year++;
        }

        // TODO: Print number of years
        printf("Years: %i\n", year);
    }
}