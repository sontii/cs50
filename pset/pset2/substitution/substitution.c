#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


int main(int argc, string argv[])  // argc -> arg count; argv -> arg vector
{
    char *key = argv[1]; //char for strchr find duuplicarte

    if (argc != 2) //only one argument
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else if (strlen(argv[1]) != 26) // only 26 char (0-25)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    else
    {
        for (int i = 0, n = strlen(argv[1]); i < n; i++) //loop check alpha
        {
            unsigned char c = key[i]; //duplicate
            if (!isalpha(argv[1][i]))
            {
                printf("Usage: ./substitution key\n"); //if not alpha break
                return 1;
            }
            else if (strchr(key + i + 1, c))
            {
                printf("The key must not contain duplicate letters.\n");
                return 1;
            }
        }
        key = argv[1]; //store key
    }

    string plainText = get_string("plaintext: "); //get input text
    string cipherText = plainText;

    for (int i = 0, n = strlen(plainText); i < n; i++) //loop plaintext
    {
        string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; //alpha array for crypt index

        if (isalpha(plainText[i]) && isupper(plainText[i]))
        {
            for (int j = 0; j < strlen(key); j++)  //loop crypt at alpha index upper
            {
                if (plainText[i] == toupper(alpha[j]))
                {
                    cipherText[i] = toupper(argv[1][j]);
                    break;
                }
            }
        }
        else if (isalpha(plainText[i]) && islower(plainText[i]))
        {
            for (int k = 0; k < strlen(alpha); k++) //loop crypt at alpha index lower
            {
                if (plainText[i] == tolower(alpha[k]))
                {
                    cipherText[i] = tolower(argv[1][k]);
                    break;
                }
            }
        }
        else
        {
            cipherText[i] = plainText[i];
        }
    }
    printf("ciphertext: %s\n", cipherText);
}
