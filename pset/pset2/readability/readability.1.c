#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>


int main(void)
{
    // Get input
    string text = get_string("Text: ");

    int letterCount = 0;
    int wordCount = 1;
    int sentenceCount = 0;
    int index = 0; //get text length
    float grade = 0; //float grade
    int gradeLast = 0; // to round grade
    int lastIndex = 0; // catch (...) only one sentence sentence

    for (int i = 0, sentenceLen = strlen(text); i < sentenceLen; i++) //loop for text
    {
        index = toupper(text[i]);   //equalize chars
        if (index > 64 && index < 91) //count chars
        {
            letterCount++;
        }
        else if (index == 32)   //count words
        {
            wordCount++;
        }
        else if (index == 39) //you're, i've +count
        {
            wordCount++;
        }
        else if (lastIndex == 46) //(catch ...)
        {

        }
        else if (index == 33 || index == 46 || index == 59 || index == 63) // count sentences
        {
            sentenceCount++;
        }
        else if (index == 83 && lastIndex == 39) // plural not 2 word
        {
            wordCount--;
        }
        lastIndex = index;

    }
    grade = 0.0588 * (100 * letterCount / wordCount) - 0.296 * (100 * sentenceCount / wordCount) - 15.8; // Coleman-Liau index
    gradeLast = round(grade); //round the grade


    if (gradeLast < 1) //check grade
    {
        printf("Before Grade 1\n");
    }
    else if (gradeLast >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", gradeLast);
    }


    //printf("%i\n", letterCount);
    //printf("%i\n", wordCount);
    //printf("%i\n", sentenceCount);
    //printf("%4.2f\n", grade);
    //printf("%i\n", gradeLast);

}
