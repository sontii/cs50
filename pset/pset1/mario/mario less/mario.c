#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for size
    int Height = 0;
    while (Height < 1 || Height > 8)
    {
        Height = get_int("Height: ");
    }


    //loop
    for (int i = 1; i <= Height; i++)
    {
        for (int j = 1; j <= Height - i; j++) //loop for space
        {
            printf(" ");
        }
        for (int k = 1; k <= i; k++) //loop for #
        {
            printf("#"); //
        }
        printf("\n");
    }
}