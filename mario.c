#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height, row, column, space;
    do
    {
        height = get_int("Enter height here: "); // asking for height
    }
    while (height < 1 || height > 8);            // condition that the int must not less then one or more than eight
    for (row = 0; row < height; row++)
    {
        for (space = 0; space < height - row - 1; space++)
        {
            printf(" ");  // untuk cetak spasi
        }
        for (column = 0; column <= row; column++)
        {
            printf("#");  //untuk cetak #
        }
        printf("\n");
    }
}