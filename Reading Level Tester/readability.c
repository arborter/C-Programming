#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
    string text = get_string("Text: ");

    int letters = 0;
    int words = 1;
    int sentences = 0;

    for (int i = 0; i < strlen(text); i ++)
    {
        if (isalpha(text[i]))
        {
            letters ++;
        }
        else if (isspace(text[i]))
        {
            words ++;
        }
        else if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences ++;
        }
    }
    float L = (float) letters / (float) words * 100;
    float S = (float) sentences / (float) words * 100;
    int grade_level = round(0.0588 * L - 0.296 * S - 15.8);
    if (grade_level < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade_level > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade_level);
    }
}