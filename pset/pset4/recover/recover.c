#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{

    // Check command-line arguments
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    // Open files
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    //declare variables

    unsigned char buffer[512];
    char filename[8]; // ###.jpg\0
    int counter = 0;
    bool jpgFound = false;
    FILE *output = NULL; //set pointer null


    //loop read data
    while (fread(&buffer, 512, 1, input) == 1)
    {

        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0) //&& buffer[512] == 0xe*
        {
            if (jpgFound == true) //if found jpg
            {
                fclose(output); // close if new jpg but no end
            }
            else
            {
                jpgFound = true; // start jpg file
            }

            // open new jpg
            sprintf(filename, "%03i.jpg", counter);
            output = fopen(filename, "w");
            counter ++;

        }

        if (jpgFound == true)
        {
            fwrite(&buffer, 512, 1, output); //write data
        }

    }
    // close files
    if (output == NULL)
    {
        fclose(output);
    }
    if (input == NULL)
    {
        fclose(input);
    }

    return 0;

}