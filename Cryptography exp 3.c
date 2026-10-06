#include <stdio.h>
#include <string.h>
#include <ctype.h>

char matrix[5][5];

void createMatrix(char key[])
{
    int used[26] = {0};
    int i, j, k = 0;
    char ch;

    used['J' - 'A'] = 1;

    for(i = 0; key[i] != '\0'; i++)
    {
        ch = toupper(key[i]);

        if(ch == 'J')
            ch = 'I';

        if(ch >= 'A' && ch <= 'Z' && used[ch - 'A'] == 0)
        {
            matrix[k / 5][k % 5] = ch;
            used[ch - 'A'] = 1;
            k++;
        }
    }

    for(ch = 'A'; ch <= 'Z'; ch++)
    {
        if(used[ch - 'A'] == 0)
        {
            matrix[k / 5][k % 5] = ch;
            used[ch - 'A'] = 1;
            k++;
        }
    }
}

void findPosition(char ch, int *row, int *col)
{
    int i, j;

    if(ch == 'J')
        ch = 'I';

    for(i = 0; i < 5; i++)
    {
        for(j = 0; j < 5; j++)
        {
            if(matrix[i][j] == ch)
            {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}

int main()
{
    char key[50], text[200], clean[200], cipher[200];
    int i, n = 0, k = 0;
    int r1, c1, r2, c2;

    printf("Enter keyword: ");
    scanf("%49s", key);

    createMatrix(key);

    printf("\nPlayfair Matrix:\n");

    for(i = 0; i < 5; i++)
    {
        int j;
        for(j = 0; j < 5; j++)
            printf("%c ", matrix[i][j]);
        printf("\n");
    }

    getchar();

    printf("\nEnter plaintext: ");
    fgets(text, sizeof(text), stdin);

    for(i = 0; text[i] != '\0'; i++)
    {
        if(isalpha(text[i]))
        {
            char ch = toupper(text[i]);

            if(ch == 'J')
                ch = 'I';

            clean[n++] = ch;
        }
    }

    clean[n] = '\0';

    for(i = 0; i < n; i++)
    {
        if(i + 1 < n && clean[i] == clean[i + 1])
        {
            cipher[k++] = clean[i];
            cipher[k++] = 'X';
        }
        else
        {
            cipher[k++] = clean[i];

            if(i + 1 < n)
            {
                cipher[k++] = clean[i + 1];
                i++;
            }
        }
    }

    if(k % 2 != 0)
        cipher[k++] = 'X';

    cipher[k] = '\0';

    for(i = 0; i < k; i += 2)
    {
        findPosition(cipher[i], &r1, &c1);
        findPosition(cipher[i + 1], &r2, &c2);

        if(r1 == r2)
        {
            cipher[i] = matrix[r1][(c1 + 1) % 5];
            cipher[i + 1] = matrix[r2][(c2 + 1) % 5];
        }
        else if(c1 == c2)
        {
            cipher[i] = matrix[(r1 + 1) % 5][c1];
            cipher[i + 1] = matrix[(r2 + 1) % 5][c2];
        }
        else
        {
            cipher[i] = matrix[r1][c2];
            cipher[i + 1] = matrix[r2][c1];
        }
    }

    printf("\nCiphertext: %s\n", cipher);

    return 0;
}
