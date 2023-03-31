#include "helpers.h"
#include <math.h>

// To cap a value at 0 and 255 inclusive we assign an output for a function as a hexadecimal number which takes
// the float value of a claculation on pixels and then adjusts it to the acceptable memory format to alter original image (8 bits)
typedef unsigned char BYTE;
BYTE cap(double a);

void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
            RGBTRIPLE rgbt;
            rgbt = image[i][j];
            // take average of each color value located at this coordinate [i][j]
            float average = (rgbt.rgbtBlue + rgbt.rgbtGreen + rgbt.rgbtRed)/3;
            rgbt.rgbtBlue = average;
            rgbt.rgbtGreen = average;
            rgbt.rgbtRed =  average;
            image[i][j] = rgbt;
            }
        }
        return;
}
// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = cap(393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
            image[i][j].rgbtGreen = cap(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            image[i][j].rgbtBlue = cap(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);
            // command: ./filter -s images/yard.bmp out.bmp
            // command: ./filter -s images/stadium.bmp out.bmp
        }
    }
    return;
}
// Reflect image horizontally

void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop through rows
    for (int i = 0; i < height; i++)
    {
        // Loop through columns
        for (int j = 0; j < width / 2; j++)
        {
            // Reflect pixels
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - (j + 1)];
            image[i][width - (j + 1)] = temp;
        }
    }    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j == 0)
            {
                if (i == 0)
                {
                    float RedAvg = (image[i][j].rgbtRed + image[i][j + 1].rgbtRed + image[i - 1][j].rgbtRed + image[i - 1][j + 1].rgbtRed)/4;
                    float GreenAvg = (image[i][j].rgbtGreen + image[i][j + 1].rgbtGreen + image[i - 1][j].rgbtGreen + image[i - 1][j + 1].rgbtGreen)/4;
                    float BlueAvg = (image[i][j].rgbtBlue + image[i][j + 1].rgbtBlue + image[i - 1][j].rgbtBlue + image[i - 1][j + 1].rgbtBlue)/4;
                    //storing avg red value in temp red
                    temp[i][j].rgbtRed = (int)round(RedAvg);
                    //storing avg green value in temp green
                    temp[i][j].rgbtGreen = (int)round(GreenAvg);
                    //storing avg blue value in temp blue
                    temp[i][j].rgbtBlue = (int)round(BlueAvg);

                }
                else if(i > 1)
                {
                    float RedAvg = (image[i][j].rgbtRed + image[i - 1][j].rgbtRed + image[i + 1][j].rgbtRed + image[i][j + 1].rgbtRed + image[i - 1][j + 1].rgbtRed + image[i + 1][j + 1].rgbtRed)/6;
                    float GreenAvg = (image[i][j].rgbtGreen + image[i - 1][j].rgbtGreen + image[i + 1][j].rgbtGreen + image[i][j + 1].rgbtGreen + image[i - 1][j + 1].rgbtGreen + image[i + 1][j + 1].rgbtGreen)/6;
                    float BlueAvg = (image[i][j].rgbtBlue + image[i - 1][j].rgbtBlue + image[i + 1][j].rgbtBlue + image[i][j + 1].rgbtBlue + image[i - 1][j + 1].rgbtBlue + image[i + 1][j + 1].rgbtBlue)/6;

// Use of temporary value instead. This is the difference in iteration.
                    temp[i][j].rgbtRed = (int)round(RedAvg);
                    temp[i][j].rgbtGreen = (int)round(GreenAvg);
                    temp[i][j].rgbtBlue = (int)round(BlueAvg);

                }
                else // i = height
                {
                    float RedAvg = (image[i][j].rgbtRed + image[i - 1][j].rgbtRed + image[i - 1][j + 1].rgbtRed + image[i][j + 1].rgbtRed)/4;
                    float GreenAvg = (image[i][j].rgbtGreen + image[i - 1][j].rgbtGreen + image[i - 1][j + 1].rgbtGreen + image[i][j + 1].rgbtGreen)/4;
                    float BlueAvg = (image[i][j].rgbtBlue + image[i - 1][j].rgbtBlue + image[i - 1][j + 1].rgbtBlue + image[i][j + 1].rgbtBlue)/4;

                    temp[i][j].rgbtRed = (int)round(RedAvg);
                    temp[i][j].rgbtGreen = (int)round(GreenAvg);
                    temp[i][j].rgbtBlue = (int)round(BlueAvg);
                }

            }
            else if(j == width)
            {
                if(i == 0)
                {
                    float RedAvg = (image[i][j].rgbtRed + image[i - 1][j].rgbtRed + image[i - 1][j - 1].rgbtRed + image[i][j - 1].rgbtRed)/4;
                    float GreenAvg = (image[i][j].rgbtGreen + image[i - 1][j].rgbtGreen + image[i - 1][j - 1].rgbtGreen + image[i][j - 1].rgbtGreen)/4;
                    float BlueAvg = (image[i][j].rgbtBlue + image[i - 1][j].rgbtBlue + image[i - 1][j - 1].rgbtBlue + image[i][j - 1].rgbtBlue)/4;

                    temp[i][j].rgbtRed = (int)round(RedAvg);
                    temp[i][j].rgbtGreen = (int)round(GreenAvg);
                    temp[i][j].rgbtBlue = (int)round(BlueAvg);

                }
                else if(i > 1)
                {
                    float RedAvg = (image[i][j].rgbtRed + image[i - 1][j].rgbtRed + image[i + 1][j].rgbtRed + image[i][j - 1].rgbtRed + image[i - 1][j - 1].rgbtRed + image[i + 1][j - 1].rgbtRed)/6;
                    float GreenAvg = (image[i][j].rgbtGreen + image[i - 1][j].rgbtGreen + image[i + 1][j].rgbtGreen + image[i][j - 1].rgbtGreen + image[i - 1][j - 1].rgbtGreen + image[i + 1][j - 1].rgbtGreen)/6;
                    float BlueAvg = (image[i][j].rgbtBlue + image[i - 1][j].rgbtBlue + image[i + 1][j].rgbtBlue + image[i][j - 1].rgbtBlue + image[i - 1][j - 1].rgbtBlue + image[i + 1][j - 1].rgbtBlue)/6;
                    temp[i][j].rgbtRed = (int)round(RedAvg);
                    temp[i][j].rgbtGreen = (int)round(GreenAvg);
                    temp[i][j].rgbtBlue = (int)round(BlueAvg);
                }
                else // i = height
                {
                    float RedAvg = (image[i][j].rgbtRed + image[i - 1][j].rgbtRed + image[i - 1][j - 1].rgbtRed + image[i][j - 1].rgbtRed)/4;
                    float GreenAvg = (image[i][j].rgbtGreen + image[i - 1][j].rgbtGreen + image[i - 1][j - 1].rgbtGreen + image[i][j - 1].rgbtGreen)/4;
                    float BlueAvg = (image[i][j].rgbtBlue + image[i - 1][j].rgbtBlue + image[i - 1][j - 1].rgbtBlue + image[i][j - 1].rgbtBlue)/4;

                    temp[i][j].rgbtRed = (int)round(RedAvg);
                    temp[i][j].rgbtGreen = (int)round(GreenAvg);
                    temp[i][j].rgbtBlue = (int)round(BlueAvg);

                }
            }
            else // j = width - 1
            {
                    float RedAvg = (image[i][j].rgbtRed + image[i - 1][j].rgbtRed + image[i + 1][j].rgbtRed + image[i][j - 1].rgbtRed + image[i - 1][j - 1].rgbtRed + image[i + 1][j - 1].rgbtRed + image[i - 1][j + 1].rgbtRed + image[i][j + 1].rgbtRed + image[i + 1][j + 1].rgbtRed)/9;
                    float GreenAvg = (image[i][j].rgbtGreen + image[i - 1][j].rgbtGreen + image[i + 1][j].rgbtGreen + image[i][j - 1].rgbtGreen + image[i - 1][j - 1].rgbtGreen + image[i + 1][j - 1].rgbtGreen + image[i - 1][j + 1].rgbtGreen + image[i][j + 1].rgbtGreen + image[i + 1][j + 1].rgbtGreen)/9;
                    float BlueAvg = (image[i][j].rgbtBlue + image[i - 1][j].rgbtBlue + image[i + 1][j].rgbtBlue + image[i][j - 1].rgbtBlue + image[i - 1][j - 1].rgbtBlue + image[i + 1][j - 1].rgbtBlue + image[i - 1][j + 1].rgbtBlue + image[i][j + 1].rgbtBlue + image[i + 1][j + 1].rgbtBlue)/9;

                    temp[i][j].rgbtRed = (int)round(RedAvg);
                    temp[i][j].rgbtGreen = (int)round(GreenAvg);
                    temp[i][j].rgbtBlue = (int)round(BlueAvg);
            }
            // command: ./filter -b images/yard.bmp out.bmp
            // command: ./filter -b images/stadium.bmp out.bmp
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {

            image[i][j].rgbtRed = temp[i][j].rgbtRed;

            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;

            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
        }
    }
    return;
}

BYTE cap(double a)
{
    if (a > 255)
    {
        return 255;
    }
    else if(a < 0)
    {
        return 0;
    }
    else
    {
        return round(a);
    }
}
