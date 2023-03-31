#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef unsigned char BYTE;
BYTE cap(int a);

int main(void)
{
    int red, green, blue;
    // unless you eclare a function to convert the number
    // to a cap of 255
    red = cap(round(393 * 200 + .769 * 100 + .189 * 234));
    green = cap(round(.349 * 246 + .686 * 123 + .168 * 246));
    blue = cap(round(.272 * 220 + .534 * 136 + .131 * 169));
    printf("R: %d G:%d B:%d\n", red, green, blue);
}

BYTE cap(a)
{
    if (a > 255)
    {
        a = 255;
        return a;
    }
    else if (a < 0)
    {
        return 0;
    }
    else
    {
        return a;
    }
}



typedef unsigned char BYTE;
BYTE cap(double a);


void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE rgbt = image[i][j];
            rgbt.rgbtRed = cap(393 * rgbt.rgbtRed + .769 * rgbt.rgbtGreen + .189 * rgbt.rgbtBlue);
            rgbt.rgbtGreen = cap(.349 * rgbt.rgbtRed + .686 * rgbt.rgbtGreen + .168 * rgbt.rgbtBlue);
            rgbt.rgbtBlue = cap(.272 * rgbt.rgbtRed + .534 * rgbt.rgbtGreen + .131 * rgbt.rgbtBlue);
            image[i][j] = rgbt;

            // command: ./filter -s images/yard.bmp out.bmp
            // command: ./filter -s images/stadium.bmp out.bmp

        }
    }
    return;
}

BYTE cap(a)
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
