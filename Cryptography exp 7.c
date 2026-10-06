#include <stdio.h>
#include <string.h>

int main()
{
    char cipher[1000];
    int i, j;

    /* Enter the ciphertext */
    strcpy(cipher,
    "53‡‡†305))6*;4826)4‡.)4‡);806*;48†8¶60))85;;]8*;:‡*8†83 "
    "(88)5*†;46(;88*96*?;8)*‡(;485);5*†2:*‡(;4956*2(5*—4)8¶8* "
    ";4069285);)6†8)4‡‡;1(‡9;48081;8:8‡1;48†85;4)485†528806*81 "
    "(‡9;48;(88;4(‡?34;48)4‡;161;:188;‡?;");

    printf("Ciphertext:\n%s\n\n", cipher);

    printf("Plaintext:\n");

    /*
       Substitution mapping obtained from frequency analysis
    */

    for(i = 0; cipher[i] != '\0'; i++)
    {
        switch(cipher[i])
        {
            case '5':
                printf("a");
                break;

            case '3':
                printf("g");
                break;

            case '‡':
                printf("o");
                break;

            case '†':
                printf("d");
                break;

            case '0':
                printf("l");
                break;

            case ')':
                printf("s");
                break;

            case '6':
                printf("i");
                break;

            case '*':
                printf("n");
                break;

            case ';':
                printf("t");
                break;

            case '4':
                printf("h");
                break;

            case '8':
                printf("e");
                break;

            case '2':
                printf("b");
                break;

            case '.':
                printf("p");
                break;

            case '¶':
                printf("v");
                break;

            case '1':
                printf("f");
                break;

            case '(':
                printf("r");
                break;

            case ':':
                printf("y");
                break;

            case '9':
                printf("m");
                break;

            case '?':
                printf("u");
                break;

            case '—':
                printf("c");
                break;

            default:
                printf("%c", cipher[i]);
        }
    }

    return 0;
}
