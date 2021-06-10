#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])  // argc -> arg count; argv -> arg vector
{
    if (argc == 2)
    {
        printf("hello, %s\n", argv[1]);
    }
    else
    {
        printf("Hello, world\n");
    }
}
