#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

// computes the Coleman-Liau index of a text
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text = get_string("Text: ");

    float numberOfLetters = count_letters(text);
    float numberOfWords = count_words(text);
    float numberOfSentences = count_sentences(text);

    // average number of letters per 100 words in the text
    float L = (numberOfLetters / numberOfWords) * 100;
    
    // the average number of sentences per 100 words in the text
    float S = (numberOfSentences / numberOfWords) * 100; 

    // The Coleman-Liau index of a text formula
    int index = round(0.0588 * L - 0.296 * S - 15.8); 

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

int count_letters(string text)
{
    int letters = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
    }
    return letters;
}

int count_words(string text)
{
    int words = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        if (isspace(text[i]) || i == strlen(text) - 1)
        {
            words++;
        }
    }
    return words;
}

int count_sentences(string text)
{
    int sentences = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == '!' || text[i] == '?' || text[i] == '.')
        {
            sentences++;
        }
    }
    return sentences;
}
