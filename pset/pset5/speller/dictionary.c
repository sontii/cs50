// Implements a dictionary's functionality

#include <stdbool.h>
#include <string.h>
#include <strings.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 10000;

// Hash table
node *table[N];
// in order, load, hash, size, check, and unload

//word counter
int counter = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO

    int hash_value = hash(word);

    //go to list index
    node *n = table[hash_value];

    //go trough list for word
    while (n != NULL)
    {
        if (strcasecmp(word, n->word) == 0)
        {
            return true;
        }

        n = n->next;
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO
    long hash_value = 0;
    for (int i = 0; i < strlen(word); i++)
    {

        hash_value += tolower(word[i]);

    }
    //modulus??
    return hash_value;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO open dict file
    FILE *input = fopen(dictionary, "r");
    if (input == NULL)
    {
        printf("Could not open %s.\n", dictionary);
        return 1;
    }

    char n_word[LENGTH + 1];
    // read string
    while (EOF != fscanf(input, "%s", n_word))
    {

        // create node
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return 1;
        }

        strcpy(n->word, n_word);
        //call hash
        int hash_value = hash(n_word);
        // insert to table
        n->next = table[hash_value];
        table[hash_value] = n;
        counter++;

    }

    fclose(input);

    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return counter;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO

    for (int i = 0; i < N; i++)
    {
        // to index
        node *n = table[i];

        while (n != NULL)
        {
            node *tmp = n;
            n = n->next;
            free(tmp);
        }

        if (n == NULL && i == N - 1)
        {
            return true;
        }
    }

    return false;
}
