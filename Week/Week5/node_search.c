#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>



int main(void)
{

    bool search(node *tree, int number)
    {
        if (tree = NULL)
        return false;
    }
    else if (number < tree->number)
    {
        return search(tree->left, number);
    }
    else if (number > tree->number)
    {
        return search(tree->right, number);
    }
    else        //only option left
    {
        return true;
    }


}

/*
last row
else if (number == tree->number)
    {
        return true;
    }
/*