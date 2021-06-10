#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (void)
{
    char *s = get_string("s: ");

    char *t = s; //only one string, t equal s address


    t[0] = toupper(t[0]);

    printf("s: %s\n", s);
    printf("t: %s\n", t);

// -------------------------

    char *j = get_string("j: ");

    char *k = malloc(strlen(j) + 1);

    if (k == NULL) // if malloc cannot allocate memory then exit program
    {
        return 1;
    }


    for (int i = 0, n = strlen(j); i <= n; i++) // <= becoause null character or i < n + 1
    {
        k[i] = j[i];
    }

    if (strlen(k) > 0)
    {
        k[0] = toupper(k[0]);
    }

    printf("j: %s\n", j);
    printf("k: %s\n", k);

    free(k);

// ------------------------

    char *q = get_string("q: ");

    char *h = malloc(strlen(q) + 1);

    if (h == NULL) // if malloc cannot allocate memory then exit program
    {
        return 1;
    }

    strcpy(h, q);

    if (strlen(h) > 0)
    {
        h[0] = toupper(h[0]);
    }

    printf("q: %s\n", q);
    printf("h: %s\n", h);

    free(h);

}