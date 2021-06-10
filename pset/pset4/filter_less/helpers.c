#include "helpers.h"
#include "math.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float gScale = 0;
    int gScaleR = 0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width ; j++)
        {
            gScale = (image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0; // 3.0 for decimal!!!
            gScaleR = round(gScale);
            image[i][j].rgbtBlue = gScaleR;
            image[i][j].rgbtGreen = gScaleR;
            image[i][j].rgbtRed = gScaleR;
        }
    }

    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{

    for (int i = 0; i < height; i++) // loop H
    {
        for (int j = 0; j < width ; j++) // loop W
        {

            float R = image[i][j].rgbtRed;   // storing RGB
            float G = image[i][j].rgbtGreen;
            float B = image[i][j].rgbtBlue;

            int sNR = round(R * 0.393 + G * 0.769 + B * 0.189); // rounding with multiply
            int sNG = round(R * 0.349 + G * 0.686 + B * 0.168);
            int sNB = round(R * 0.272 + G * 0.534 + B * 0.131);

            if (sNR > 255)   // 255 cap check
            {
                sNR = 255;
            }

            image[i][j].rgbtRed = sNR; // store sepia value

            if (sNG > 255)
            {
                sNG = 255;
            }
            image[i][j].rgbtGreen = sNG;

            if (sNB > 255)
            {
                sNB = 255;
            }
            image[i][j].rgbtBlue = sNB;
        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{

    for (int i = 0; i < height; i++) // loop H
    {
        for (int j = 0; j < width / 2; j++) // loop W replace to half
        {
            RGBTRIPLE tmp = image[i][j]; // red blue and empty glass tmp as first row
            image[i][j] = image[i][width - (j + 1)]; // right as last at row
            image[i][width - (j + 1)] = tmp;
        }
    }

    return;
}


// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{

    // create tmp img, if changed while loop cannot be check original pixel
    RGBTRIPLE tmp[height][width];

    for (int i = 0; i < height; i++) // loop tmp H
    {
        for (int j = 0; j < width; j++) // loop tmp W
        {

            tmp[i][j] = image[i][j];

        }
    }



    //loop again
    for (int i = 0; i < height; i++) // loop  h
    {
        for (int j = 0; j < width; j++) // loop W
        {

            float R = 0; //floats; int not work
            float B = 0;
            float G = 0;
            float counter = 0;

            for (int k = -1; k < 2; k++) // pixel height -1 - +1
            {
                for (int l = -1; l < 2; l++) // pixel width -1 - +1
                {
                    
                    if (i + k >= 0 && j + l >= 0 && i + k <= height - 1 && j + l <= width - 1) //pixel outside h skip
                    {

                        R += tmp[i + k][j + l].rgbtRed;
                        G += tmp[i + k][j + l].rgbtGreen;
                        B += tmp[i + k][j + l].rgbtBlue;
                        counter++;

                    }
                }

            }

            // calculate aVg colors
            R = R / counter;
            G = G / counter;
            B = B / counter;
            if (R > 255)   // 255 cap check
            {
                R = 255;
            }
            if (G > 255)
            {
                G = 255;
            }
            if (B > 255)
            {
                B = 255;
            }

            image[i][j].rgbtRed = round(R);
            image[i][j].rgbtGreen = round(G);
            image[i][j].rgbtBlue = round(B);
            R = 0;
            G = 0;
            B = 0;

        }

    }

    return;
}
