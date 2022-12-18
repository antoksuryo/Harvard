#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    typedef uint8_t BYTE;

    // menyimpan blocks 512 ke array
    BYTE buffer[512];
    int bacaBytes, count = 0;

    // char filename[8]
    char filename[8];


    // mebuka file untuk dibaca
    FILE *f = fopen(argv[1], "r");
    // mengecek input file nya adalah benar
    // pointer file untuk recover gambar
    FILE *gambar = NULL;


    // mengecek argumen adalah 2
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE");
        return 1;
    }
    //read the blocks of 512 bytes
    // melacak nomor dari gambar yang telah di generate
    while (1)
    {
        bacaBytes = fread(buffer, sizeof(BYTE), 512, f);
        //cek jika bytes mengindikasi awalan dari JPEG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && ((buffer[3] & 0xf0) == 0xe0))
        {
            if (count == 0)
            {
                // membuat nama file dari jpeg
                sprintf(filename, "%03i.jpg", count);

                //membuat output file untuk penulisan
                gambar = fopen(filename, "w");
                fwrite(buffer, sizeof(BYTE), bacaBytes, gambar);

                // hitung jumlah gambar yang ditemukan
                count++;
            }
            // cek jika output sudah digunakan sebagai input yang valid
            else
            {
                fclose(gambar);
                sprintf(filename, "%03i.jpg", count);
                gambar = fopen(filename, "w");
                fwrite(buffer, sizeof(BYTE), bacaBytes, gambar);
                count++;
            }
        }
        else if (count != 0)
        {
            fwrite(buffer, sizeof(BYTE), bacaBytes, gambar);
            if (bacaBytes == 0)
            {
                fclose(gambar);
                fclose(f);
                return 0;
            }
        }
    }
    fclose(gambar);
    fclose(f);
}
