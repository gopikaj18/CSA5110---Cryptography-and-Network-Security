#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char text[100], key[100], cipher[100];
    int i, j = 0;

    printf("Enter plaintext: ");
    fgets(text, sizeof(text), stdin);

    printf("Enter key: ");
    scanf("%s", key);

    for(i = 0; text[i] != '\0'; i++)
    {
        if(isalpha(text[i]))
        {
            char p = toupper(text[i]);
            char k = toupper(key[j % strlen(key)]);

            cipher[i] = ((p - 'A') + (k - 'A')) % 26 + 'A';
            j++;
        }
        else
        {
            cipher[i] = text[i];
        }
    }

    cipher[i] = '\0';

    printf("Ciphertext: %s", cipher);

    return 0;
}
