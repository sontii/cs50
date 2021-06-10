#include <cs50.h>
#include <stdio.h>
#include <string.h>


typedef struct
{
    string name;
    string number;
}
person;

const int NUMBER = 10;

int main (void)
{
    person people[NUMBER];


    for (int i =0; i < NUMBER; i++)
    {
        people[i].name = get_string("What's the name? ")
        people[i].number = get_string("What's the number? ")
    }


    //people[0].name = "Brian";
    //people[0].number = "+1-246-234";

    //people[1].name = "David";
    //people[1].number = "+1-1000-700";


    for (int i = 0; i < 2; i++)
    {
        if(strcmp(people[i].name, "David") == 0)
        {
            printf("Found %s\n", people[i].number);
            return 0;
        }
    }
    printf("Not Found\n");
    return 0;

}