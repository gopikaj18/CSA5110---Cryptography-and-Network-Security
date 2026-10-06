#include <stdio.h>

char matrix[5][5] = {
    {'R','O','Y','A','L'},
    {'N','E','W','Z','D'},
    {'V','B','C','F','G'},
    {'H','I','K','M','P'},
    {'Q','S','T','U','X'}
};

void findPosition(char ch, int *row, int *col)
{
    int i, j;

    if (ch == 'J')
        ch = 'I';

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if (matrix[i][j] == ch)
            {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}

void decryptPair(char a, char b, char *x, char *y)
{
    int r1, c1, r2, c2;
    int temp;

    findPosition(a, &r1, &c1);
    findPosition(b, &r2, &c2);

    /* Same row */
    if (r1 == r2)
    {
        c1 = (c1 + 4) % 5;
        c2 = (c2 + 4) % 5;
    }

    /* Same column */
    else if (c1 == c2)
    {
        r1 = (r1 + 4) % 5;
        r2 = (r2 + 4) % 5;
    }

    /* Rectangle rule */
    else
    {
        temp = c1;
        c1 = c2;
        c2 = temp;
    }

    *x = matrix[r1][c1];
    *y = matrix[r2][c2];
}

int main()
{
    char cipher[] =
    "KXJEYUREBEZWEHEWRYTUHEYFSKREHEGOYFIWTTTUOLKSY"
    "CAJPOBOTEIZONTXBYBNTGONEYCUZWRGDSONSXBOUYWRHE"
    "BAAHYUSEDQ";

    char plain[200];
    int i, j = 0;
    char x, y;

    printf("Playfair Matrix:\n");

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }

    printf("\nCiphertext:\n");
    printf("KXJEY UREBE ZWEHE WRYTU HEYFS\n");
    printf("KREHE GOYFI WTTTU OLKSY CAJPO\n");
    printf("BOTEI ZONTX BYBNT GONEY CUZWR\n");
    printf("GDSON SXBOU YWRHE BAAHY USEDQ\n");

    j = 0;

    /*
       The original message contains TT.
       TT was transmitted directly and is not a normal
       Playfair pair, so keep it as TT.
    */

    for (i = 0; cipher[i] != '\0'; i += 2)
    {
        /* Special TT in the original message */
        if (cipher[i] == 'T' && cipher[i + 1] == 'T')
        {
            plain[j++] = 'T';
            plain[j++] = 'T';
        }
        else
        {
            decryptPair(cipher[i], cipher[i + 1], &x, &y);

            plain[j++] = x;
            plain[j++] = y;
        }
    }

    plain[j] = '\0';

    printf("\nDecrypted Text:\n");
    printf("%s\n", plain);

    printf("\nFinal Plaintext:\n");
    printf("PT BOAT ONE OWE NINE LOST IN ACTION IN BLACKETT\n");
    printf("STRAIT TWO MILES SW MERESU COVE X CREW OF TWELVE X\n");
    printf("REQUEST ANY INFORMATION X\n");

    return 0;
}
