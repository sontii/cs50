#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main (void)
{
    char *s = get_string("s: ");
    char *t = get_string("t: ");


    printf("%p\n", s); //address
    printf("%p\n", s);

    printf("%s\n", s); //string
    printf("%s\n", s);


    if (s == t) //compared address!!! return value is adress
    {
        printf("Same\n");
    }
    else
    {
        printf("Different\n");
    }

    if (strcmp(s, t) == 0) //compare string
    {
        printf("Same\n");
    }
    else
    {
        printf("Different\n");
    }



}