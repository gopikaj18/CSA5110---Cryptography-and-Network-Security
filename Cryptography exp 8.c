#include <stdio.h>
#include <ctype.h>

int main()
{
    char key[20];
    char cipher[27];
    char text[100];

    int used[26] = {0};
    int i, j = 0, pos;
    char ch;

    printf("Enter keyword: ");
    scanf("%s", key);

    /* Add keyword letters */
    for(i = 0; key[i] != '\0'; i++)
    {
        ch = toupper(key[i]);

        if(used[ch - 'A'] == 0)
        {
            cipher[j] = ch;
            used[ch - 'A'] = 1;
            j++;
        }
    }

    /* Add remaining alphabet letters */
    for(ch = 'A'; ch <= 'Z'; ch++)
    {
        if(used[ch - 'A'] == 0)
        {
            cipher[j] = ch;
            used[ch - 'A'] = 1;
            j++;
        }
    }

    cipher[26] = '\0';

    printf("\nPlain Alphabet : ABCDEFGHIJKLMNOPQRSTUVWXYZ\n");
    printf("Cipher Alphabet: %s\n", cipher);

    getchar();

    printf("\nEnter plaintext: ");
    fgets(text, sizeof(text), stdin);

    /* Encryption */
    for(i = 0; text[i] != '\0'; i++)
    {
        if(text[i] >= 'A' && text[i] <= 'Z')
        {
            pos = text[i] - 'A';
            text[i] = cipher[pos];
        }
        else if(text[i] >= 'a' && text[i] <= 'z')
        {
            pos = text[i] - 'a';
            text[i] = tolower(cipher[pos]);
        }
    }

    printf("Ciphertext: %s", text);

    return 0;
}
