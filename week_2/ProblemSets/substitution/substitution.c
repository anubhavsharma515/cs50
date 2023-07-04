#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>


const int LETTERS = 26;
const int LOW = 97;

bool only_unique_letters(string code);

int main(int argc, string argv[]) 
{
    if (argc == 2 && strlen(argv[1]) == 26)
    {
        if(only_unique_letters(argv[1]) == false)
        {
            printf("Usage: ./substitution key");
            return 1;
        }
    }
    else
    { 
        printf("Usage: ./substitution key"); 
        return 1;
    }

    string plaintext = get_string("plaintext:  ");
    int map[LETTERS]; 
    printf("ciphertext: ");

    for (int i = 0; i < strlen(plaintext) ; ++i)
    {
        int t = tolower(plaintext[i]) - LOW;
        int sub = argv[1][t]; 
        if (isupper(plaintext[i]))
        {
            printf("%c", toupper(sub));
        }
        else if (islower(plaintext[i]))
        {
            printf("%c", tolower(sub));
        }
        else {
            printf("%c", plaintext[i]);
        }
    }

    printf("\n");
    
    return 0;
}

bool only_unique_letters(string code)
{
    int occurrences[LETTERS] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    int sum = 1;
    for (int i = 0; i < LETTERS; ++i)
    {
        if (isalpha(code[i]))
        {
             occurrences[tolower(code[i]) - LOW] += 1; 
        }
        else
        {
            return false;
        }
    }

    for (int j = 0; j < LETTERS; ++j)
    { 
        if (occurrences[j] > 1)
        {
            return false;
        };
    }
    return true;
}