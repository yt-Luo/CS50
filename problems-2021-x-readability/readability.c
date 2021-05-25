#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    string text = get_string("Text: ");

    int space = 0, letter = 0, sentence = 0;

    for (int i = 0, n = strlen(text); i < n ; i++)
    {
        char c = text[i];
        if (isspace(c))
        {
            space += 1;
        }
        else if (isalpha(c))
        {
            letter += 1;
        }
        //consider any sequence of characters that ends with a . or a ! or a ? to be a sentence 
        else if (c == '.' || c == '!' || c == '?')
        {
            sentence += 1;
        }
    }

    int word = space + 1;

    //L is the average number of letters per 100 words in the text, and S is the average number of sentences per 100 words in the text
    //Recall that, when dividing values of type int in C, the result will also be an int, with any remainder (i.e., digits after the decimal point) discarded. 
    //Put another way, the result will be “truncated.” You might want to cast your one or more values to float before performing division when calculating L and S!
    float l = letter, w = word, s = sentence;
    float L = l / w * 100;
    float S = s / w * 100;

    int index = round(0.0588 * L - 0.296 * S - 15.8);

    //resulting index number is 16 or higher, your program should output "Grade 16+" instead of giving the exact index number. 
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    //If the index number is less than 1, your program should output "Before Grade 1"
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %d\n", index);
    }
}