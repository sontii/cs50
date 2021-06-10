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

                    if (i + k >= 0 && j + l >= 0 && i + k <= height - 1 && j + l <= width - 1) //pixel outside skip
                    {

                        R += tmp[i + k][j + l].rgbtRed;
                        G += tmp[i + k][j + l].rgbtGreen;
                        B += tmp[i + k][j + l].rgbtBlue;
                        counter++;

                    }

                }

            }

            // set values
            image[i][j].rgbtRed = round(R / counter);
            image[i][j].rgbtGreen = round(G / counter);
            image[i][j].rgbtBlue = round(B / counter);

        }
    }

    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
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

    // gx and gy as reference
    int GX[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int GY[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    //loop again
    for (int i = 0; i < height; i++) // loop  h
    {
        for (int j = 0; j < width; j++) // loop W
        {

            float XR = 0; //floats for precise
            float XB = 0;
            float XG = 0;
            float YR = 0;
            float YB = 0;
            float YG = 0;

            for (int k = -1; k < 2; k++) // pixel height -1 - +1
            {
                for (int l = -1; l < 2; l++) // pixel width -1 - +1
                {

                    if (i + k >= 0 && j + l >= 0 && i + k <= height - 1 && j + l <= width - 1) //pixel outside skip
                    {

                        XR += tmp[i + k][j + l].rgbtRed * GX[k + 1][l + 1];
                        XG += tmp[i + k][j + l].rgbtGreen * GX[k + 1][l + 1];
                        XB += tmp[i + k][j + l].rgbtBlue * GX[k + 1][l + 1];
                        YR += tmp[i + k][j + l].rgbtRed * GY[k + 1][l + 1];
                        YG += tmp[i + k][j + l].rgbtGreen * GY[k + 1][l + 1];
                        YB += tmp[i + k][j + l].rgbtBlue * GY[k + 1][l + 1];

                    }

                }

            }
            //Sobel operator
            int R = round(sqrt(XR * XR + YR * YR));
            int G = round(sqrt(XG * XG + YG * YG));
            int B = round(sqrt(XB * XB + YB * YB));

            //check cap
            if (R > 255)
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

            // set values
            image[i][j].rgbtRed = R;
            image[i][j].rgbtGreen = G;
            image[i][j].rgbtBlue = B;

        }
    }


    return;
}
