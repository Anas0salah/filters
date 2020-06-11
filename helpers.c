#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop for number fo Rows
    for (int i = 0 ; i < height ; i++)
    {
        // Loop for number of pixel in the Row
        for (int a = 0 ; a < width; a++)
        {
            // calculate the avrage of each pixel of coler
            float avreg_of_RGB = (image[i][a].rgbtRed + image[i][a].rgbtGreen + image[i][a].rgbtBlue)/3.00;
            int New_Avreg = round(avreg_of_RGB);

            image[i][a].rgbtRed = New_Avreg;
            image[i][a].rgbtGreen = New_Avreg;
            image[i][a].rgbtBlue = New_Avreg;
        }
    }
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
        // Loop for number fo Rows
        for (int Rows = 0 ; Rows < height ; Rows++)
    {
        // Loop for number of pixel in the Row
        for (int pixel = 0 ; pixel < width; pixel++)
        {
            int sepiaRed = round ((0.393 *image[Rows][pixel].rgbtRed) + (0.769 * image[Rows][pixel].rgbtGreen) + (0.189 * image[Rows][pixel].rgbtBlue));
            int sepiaGreen = round ((0.349 *image[Rows][pixel].rgbtRed) + (0.686 * image[Rows][pixel].rgbtGreen) + (0.168 * image[Rows][pixel].rgbtBlue));
            int sepiaBlue = round ((0.272 *image[Rows][pixel].rgbtRed) + (0.534 * image[Rows][pixel].rgbtGreen) + (0.131 * image[Rows][pixel].rgbtBlue));
            // for new sepia color
            image[Rows][pixel].rgbtRed = (sepiaRed > 255) ? 255 : sepiaRed;
            image[Rows][pixel].rgbtGreen = (sepiaGreen > 255) ? 255 : sepiaGreen;
            image[Rows][pixel].rgbtBlue = (sepiaBlue > 255) ? 255 : sepiaBlue;
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
        for (int r = 0; r < height; r++)
        {
            for (int t = 0; t < (width/2); t++)
            {
                int Red = image[r][t].rgbtRed;
                int Green = image[r][t].rgbtGreen;
                int Blue = image[r][t].rgbtBlue;

                image[r][t].rgbtRed = image[r][width - t - 1].rgbtRed;
                image[r][t].rgbtGreen = image[r][width - t - 1].rgbtGreen;
                image[r][t].rgbtBlue = image[r][width - t - 1].rgbtBlue;

                image[r][width - t - 1].rgbtRed = Red;
                image[r][width - t - 1].rgbtGreen = Green;
                image[r][width - t - 1].rgbtBlue = Blue;
            }
        }
}
// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int Sum_Red = 0;
            int sum_Green = 0;
            int Sum_Blue = 0;
            float counter = 0.00;

            // loop for height in blur Box
            for (int o = -1; o < 2; o++ )
            {
                // loop for width in blur Box
                for(int k = -1; k < 2; k++)
                {
                    if(i + o < 0 || i + o > height -1 || j + k < 0 || j + k > width -1)
                    {
                    continue;
                    }
                    Sum_Red += image[i+o][j+k].rgbtRed;
                    sum_Green += image[i+o][j+k].rgbtGreen;
                    Sum_Blue += image[i+o][j+k].rgbtBlue;

                    counter++;
                }
            }
        copy[i][j].rgbtRed = round(Sum_Red/counter);
        copy[i][j].rgbtGreen = round(sum_Green/counter);
        copy[i][j].rgbtBlue = round(Sum_Blue/counter);
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = copy[i][j].rgbtRed;
            image[i][j].rgbtGreen = copy[i][j].rgbtGreen;
            image[i][j].rgbtBlue = copy[i][j].rgbtBlue;
        }
    }
}

