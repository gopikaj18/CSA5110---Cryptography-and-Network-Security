#include <stdio.h>

int main()
{
    char cipher[100];
    int i, c, p;

    printf("Enter ciphertext: ");
    scanf("%s", cipher);

    for(i = 0; cipher[i] != '\0'; i++)
    {
        c = cipher[i] - 'A';

        p = (9 * (c - 15)) % 26;

        if(p < 0)
            p = p + 26;

        cipher[i] = p + 'A';
    }

    printf("Plaintext: %s", cipher);

    return 0;
}
