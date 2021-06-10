#include <cs50.h>
#include <stdio.h>


void draw (int h);

int main (void)
{
    int height = get_int("Height: ");
    draw(height);

}

void draw (int h)
{
    if (h == 0)
    {
        return;
    }
    draw(h - 1); // function call it self so if 0 return

    for (int i = 0 ; i < h; i++)
    {
        printf("#");
    }

    printf("\n");
}