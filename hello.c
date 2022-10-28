#include <cs50.h>
#include <stdio.h> //untuk input studio

int main(void)
{
    string answer = get_string("whats your name? ");  // meminta jawaban
    printf("hello, %s \n", answer);  // vetak halo plus jawaban
}