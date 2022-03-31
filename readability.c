#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
    int textlength, letters = 0, sentence = 0, words = 1,  index;
    float calculate;
    //Prompt For Text to be Graded
    string text = get_string("Enter Text: \n");
    //Lentgth of all charaters in Text
    textlength = strlen(text);
    for (int i = 0; i <= textlength; i++)
    {
        //Counts number of albhabetical letters in text
        if ((text[i] >= 'A' && text[i] <= 'Z') || (text[i] >= 'a' && text[i] <= 'z'))
        {
            letters++;
        }
        //Counts Number of Sentences
        else if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentence++;
        }
        //Counts Number of words
        else if (isspace(text[i]) != 0)
        {
            words++;
        }
    }
    //Implementing Coleman-Liau Formula
    calculate = (0.0588 * letters / words * 100) - (0.296 * sentence / words * 100) - 15.8;
    //Rounding the Calculated data
    index = round(calculate);
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}