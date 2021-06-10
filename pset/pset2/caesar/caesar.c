#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

string compute_score(string plainText);

int main(int argc, string argv[])  // argc -> arg count; argv -> arg vector
{
    int key = 0; //store secret key

    if (argc != 2) //only one argument
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        for (int i = 0, n = strlen(argv[1]); i < n; i++) //loop check digit
        {

            if (isdigit(argv[1][i]))
            {

            }
            else
            {
                printf("Usage: ./caesar key\n"); //if not digit break
                return 1;
            }
        }
        key = atoi(argv[1]); //convert string to int
    }

    string plainText = get_string("plaintext: "); //get input text
    string cipherText = plainText;

    for (int i = 0, n = strlen(plainText); i < n; i++) //loop plaintext
    {
        if (isalpha(plainText[i]) && isupper(plainText[i]))
        {
            cipherText[i] = ((plainText[i] - 65 + key) % 26) + 65;
        }
        else if (isalpha(plainText[i]) && islower(plainText[i]))
        {
            cipherText[i] = ((plainText[i] - 97 + key) % 26) + 97;
        }
        else
        {
            cipherText[i] = plainText[i];
        }
    }
    printf("ciphertext: %s\n", cipherText);
}
