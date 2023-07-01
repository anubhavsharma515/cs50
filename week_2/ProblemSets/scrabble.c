#include <stdio.h>
#include <string.h>
#include <ctype.h>

int get_score(char word[]);

const int N = 26;
const int SCORES[N] = {1,3,3,2,1,4,2,4,1,8,5,1,3,1,1,3,10,1,1,1,1,4,4,8,4,10};
const char LETTERS[N] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

int main(void) {

    char player_1[N];
    char player_2[N];

    printf("Player 1: ");
    scanf("%s", player_1);

    printf("Player 2: ");
    scanf("%s", player_2);

    int score_1 = get_score(player_1);
    int score_2 = get_score(player_2);

    if (score_1 > score_2)
    {
        printf("Player 1 wins!");
    }
    else if (score_1 < score_2)
    {
        printf("Player 2 wins!");
    }
    else {
        printf("Tie!");
    }
}

int get_score(char word[]) {

    int score = 0;

    for(int i = 0, n = strlen(word); i < n; ++i) {
        for(int j = 0; j < N; ++j) { 
            if (LETTERS[j] == tolower(word[i])) 
            { 
                score+= SCORES[j]; 
            } 
        }
    }
    return score;
}