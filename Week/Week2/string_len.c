#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{

    string s = get_string("Input:  ");
    printf("Output: ");


    //for (int i = 0; s[i] != '\0'; i++) firt < give back input
    //---------------------------------------------------------
    // int n = strlen(s); << initialise this in the for loop statment
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        printf("%c", s[i]);

    }
    printf("\n");


}