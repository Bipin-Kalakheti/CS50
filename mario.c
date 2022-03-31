#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    //Prompt for Height
    do
    {
        height = get_int("height: ");
    }
    //check if the conditions for height are met or not
    while (height > 8 || height < 1);
    //Loop for height times
    for (int row = 0; row < height; row++)
    {
        //this loops add space before #
        for (int space = 0; space < height - row - 1; space++)
        {
            printf(" ");
        }
        //This Loops adds left side of hashes
        for (int column = 0; column <= row; column++)
        {
            printf("#");
        }
        printf("  ");
        //This loops add right side of hasses
        for (int column = 0; column <= row; column++)
        {
            printf("#");
        }
        printf("\n");
    }
}