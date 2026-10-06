#include <stdio.h>
#include <string.h>

char matrix[5][5] = {
    {'M','F','H','I','K'},
    {'U','N','O','P','Q'},
    {'Z','V','W','X','Y'},
    {'E','L','A','R','G'},
    {'D','S','T','B','C'}
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

void encryptPair(char a, char b, char *x, char *y)
{
    int r1, c1, r2, c2;

    findPosition(a, &r1, &c1);
    findPosition(b, &r2, &c2);

    /* Same row */
    if (r1 == r2)
    {
        *x = matrix[r1][(c1 + 1) % 5];
        *y = matrix[r2][(c2 + 1) % 5];
    }

    /* Same column */
    else if (c1 == c2)
    {
        *x = matrix[(r1 + 1) % 5][c1];
        *y = matrix[(r2 + 1) % 5][c2];
    }

    /* Rectangle */
    else
    {
        *x = matrix[r1][c2];
        *y = matrix[r2][c1];
    }
}

int main()
{
    char text[] = "MUSTSEEYOUOVERCADOGANWESTCOMINGATONCE";

    char prepared[100];
    char cipher[100];

    int i = 0;
    int j = 0;
    char a, b;
    char x, y;

    /* Prepare plaintext */

    while (text[i] != '\0')
    {
        a = text[i];

        if (text[i + 1] == '\0')
        {
            prepared[j++] = a;
            prepared[j++] = 'X';
            i++;
        }
        else
        {
            b = text[i + 1];

            if (a == b)
            {
                prepared[j++] = a;
                prepared[j++] = 'X';
                i++;
            }
            else
            {
                prepared[j++] = a;
                prepared[j++] = b;
                i = i + 2;
            }
        }
    }

    prepared[j] = '\0';

    /* Encrypt the prepared text */

    i = 0;
    j = 0;

    while (prepared[i] != '\0')
    {
        a = prepared[i];
        b = prepared[i + 1];

        encryptPair(a, b, &x, &y);

        cipher[j++] = x;
        cipher[j++] = y;

        i = i + 2;
    }

    cipher[j] = '\0';

    /* Display matrix */

    printf("Playfair Matrix:\n");

    printf("M   F   H   I/J K\n");
    printf("U   N   O   P   Q\n");
    printf("Z   V   W   X   Y\n");
    printf("E   L   A   R   G\n");
    printf("D   S   T   B   C\n");

    printf("\nPlaintext:\n");
    printf("Must see you over Cadogan West. Coming at once.\n");

    printf("\nPrepared Text:\n");
    printf("%s\n", prepared);

    printf("\nCiphertext:\n");
    printf("%s\n", cipher);

    return 0;
}
