#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])  // argc -> arg count; argv -> arg vector
{
    if (argc != 2)
    {
        printf("missing command-line argument\n");
        return 1;
    }
    printf("hello, %s\n", argv[1]);
    return 0;
}