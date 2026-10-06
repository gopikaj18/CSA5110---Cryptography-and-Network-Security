#include <stdio.h>

int main()
{
    char text[100], key[27];
    int i, pos;

    printf("Enter plaintext: ");
    gets(text);

    printf("Enter 26 letter key: ");
    scanf("%s", key);

    for(i = 0; text[i] != '\0'; i++)
    {
        if(text[i] >= 'A' && text[i] <= 'Z')
        {
            pos = text[i] - 'A';
            text[i] = key[pos];
        }
    }

    printf("Ciphertext: %s", text);

    return 0;
}
