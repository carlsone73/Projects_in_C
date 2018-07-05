#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


int main(int argc, string argv[])
{
    if (argc != 2)
    {
        return 1;
    }

    int i = atoi(argv[1]);

    printf("plaintext:  ");
    string s = get_string();

    printf("ciphertext: ");
    for (int j = 0; j < strlen(s); j++)
    {
        if (isalpha(s[j]))
        {

            if (isupper(s[j]))
            {
                int c = ((s[j]-65 + i) % 26) + 65;
                printf("%c", c);
            }
            if (islower(s[j]))
            {
                int c = ((s[j]-97 + i) % 26) + 97;
                printf("%c", c);
            }
        }
        else
        {
            printf("%c", s[j]);
        }
    }
    printf("\n");
}