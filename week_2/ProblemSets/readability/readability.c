#include <stdio.h>
#include <ctype.h>
#include <string.h>

float get_index(int letters, int words, int sentences);
int count_letters(char text[]);
int count_words(char text[]);
int count_sentences(char text[]);

int main(void) 
{
    char text[1000];
    printf("Text: ");
    fgets(text, sizeof(text), stdin);

    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    float grade = get_index(letters, words, sentences);
    if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else { 
        printf("Grade %.0f\n", grade);
    }
}

int count_letters(char text[])
{
    int characters = 0;
    for (int i = 0, n = strlen(text); i < n; ++i) {
        if (isalpha(text[i]))
        {
            characters+=1;
        }
    }
    return characters;
}

int count_words(char text[]) 
{
    int words = 0;
    for (int i = 0, n = strlen(text); i < n; ++i) {
        if (isspace(text[i+1]))
        {
            words+=1;
        }
    }
    return words;
}
int count_sentences(char text[])
{
    int sentences = 0;
    for (int i = 0, n = strlen(text); i < n; ++i) {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences+=1;
        }
    }
    return sentences;
}

float get_index(int letters, int words, int sentences) 
{
    float L = 0.0;
    float S = 0.0;

    L = letters * 1.0 / words * 100;
    S = sentences * 1.0 / words * 100;

    return ((0.0588 * L) - (0.296 * S) - 15.8);
}