#include <cs50.h>
#include <stdio.h>


void swap (int *a, int *b);

int main (void)
{
    int x = 1;
    int y = 2;

    printf("x is: %i, y is: %i\n", x, y);
    swap(&x, &y);                           // passing only adress --->> &
    printf("x is: %i, y is: %i\n", x, y);

}

void swap (int *a, int *b) // changing at adress * asterix
{
    int tmp = *a;
    *a = *b;
    *b = tmp;

}