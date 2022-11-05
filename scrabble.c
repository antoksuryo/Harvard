#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Print the winner player 1 or 2
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int compute_score(string word)
{
    // TODO: menghitung dan mengembalikan score string
    int score = 0;

    for (int j = 0; j < strlen(word); j++) //awalan, kondisi terjadi, dan penambahan
    {
        if (isupper(word[j]))//(identifikasi karakter huruf besar)
        {
            score = score + POINTS[word[j] - 65];  // dikurang 65 sesuai tabel scsi
        }
        else if (islower(word[j])) //(identifikasi karakter adalah kecil )
        {
            score = score + POINTS[word[j] - 97]; // dikurang 97 sesuai tabel scsi
        }

    }
    return score;
}