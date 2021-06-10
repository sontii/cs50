#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (void)
{
    char *s = malloc(4); //allocate the right size of memory!
    s[0] = 'H';
    s[1] = 'i';
    s[2] = '!';
    s[3] = '\0';


    printf("s: %s\n", s);

    free(s); // must free allocated memory

}