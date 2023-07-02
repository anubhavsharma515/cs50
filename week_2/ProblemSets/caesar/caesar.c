#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

const int CAPITAL_HIGH = 90;
const int CAPITAL_LOW = 64;
const int LOWER_LOW = 96;
const int LOWER_HIGH = 122;

const int N_DIGITS = 26;

bool only_digits(string s);
char rotate(char c, int n);

int main(int argc, string argv[]) 
{

    if (argc == 1 || argc > 2)
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }
    else if (argc == 2 && only_digits(argv[1]) == false) 
    { 
        printf("Usage: %s key\n", argv[0]); 
        return 1;
    } 

    int key = atoi(argv[1]);
    string plaintext = get_string("plaintext:  ");
    printf("ciphertext: ");

    for (int i = 0; i < strlen(plaintext); ++i)
    {
        if (isalpha(plaintext[i]))
        { 
            printf("%c", rotate(plaintext[i], key));
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }

    printf("\n");
    return 0;
}

bool only_digits(string s)
{
    for(int i = 0; i < strlen(s); ++i)
    {
        if(isalpha(s[i]))
        {
            return false;
        }
    }

    return true;
}

char rotate(char c, int n)
{
    int ch = c;
    int increment = n;
    if (n > 26) 
    {
        increment = n % N_DIGITS;
    }
    
    if (isupper(c) && (increment + ch > CAPITAL_HIGH)) 
    { 
        return CAPITAL_LOW + increment - (CAPITAL_HIGH - ch); 
    }
    else if (islower(c) && (increment + ch > LOWER_HIGH)) 
    { 
        return LOWER_LOW + increment - (LOWER_HIGH - ch); 
    }
    else
    {
        return (ch + increment);
    }
}