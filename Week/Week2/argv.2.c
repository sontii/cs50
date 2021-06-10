#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])  // argc -> arg count; argv -> arg vector
{
    if (argc ==2)
    {
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            printf("%c\n", argv[1][i]);
        }
    }
}
