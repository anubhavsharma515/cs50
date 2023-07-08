#include "helpers.h"
#include <stdio.h>  

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    // Change all black pixels to a color of your choosing
    for (int i = 0; i < width; ++i)
    {
        for (int j = 0; j < height; ++j)
        {
            if (image[i][j].rgbtBlue == 0x00 && image[i][j].rgbtGreen == 0x00 && image[i][j].rgbtRed == 0x00)
            {
                image[i][j].rgbtBlue = 0xf3;
                image[i][j].rgbtGreen = 0x1f;
                image[i][j].rgbtRed = 0x3d;
            }
        }
    }
}
