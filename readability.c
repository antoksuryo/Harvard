#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>
#include <ctype.h>


int  main(void)
{
    // permintaan teks kepada user
    string teks = get_string("teks: ");


    // menghitung jumlah huruf menggunakan strlen
    float huruf = 0;
    for (int i = 0, n = strlen(teks); i < n; i++)
    {
        if ((isalpha(teks[i])))
        {
            huruf++;
        }
    }

    // menghitung  jumlah kata dengan menghitung spasi + 1 spasi diujung sebagai awal
    float katakata = 1;
    for (int i = 0, n = strlen(teks); i < n; i++)
    {
        if (teks[i] == ' ')
        {
            katakata++;
        }
    }

    // menghitung jumlah kalimat dengan menghitung titik tanda tanya dan tanda seru
    float kalimat = 0;
    for (int i = 0, n = strlen(teks); i < n; i++)
    {
        if (teks[i] == '?' || teks[i] == '!' || teks[i] == '.')
        {
            kalimat++;
        }
    }

    // menghitung medium huruf dan kalimat per 100 kata
    float L = 100 * (huruf / katakata);
    float S = 100 * (kalimat / katakata);
    // Calculate Coleman-Liau index
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    // mengembalikan hasil
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

