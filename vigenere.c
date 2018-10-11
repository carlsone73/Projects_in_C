//caesar encrypts strings using the vigenere encryption where you encrypt one string with another keyword
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    //checking that argc is 2 and argv only contains alpha characters
    if (argc != 2 || argv[1] == 0)
    {
        return 1;
    }

    string k = argv[1];
    int p = strlen(k);
    int r = 0;

    for (int i = 0; i < p; i++)
    {
        if (isalpha(k[i]))
        {
            r++;
        }
    }
    if (r < p)
    {
        return 1;
    }

    //converts the number you entered as a key to an int
    for (int i = 0; i < p; i++)
    {
        k[i] = (int) tolower(k[i]) - 97;
    }

    //user inputs string to be encrypted
    string s = get_string("plaintext: ");

    //encrypting the text using the keyword
    printf("ciphertext: ");
    for (int i = 0, n = strlen(s), j = 0; i < n; i++)
    {
        if (isalpha(s[i]) && isupper(s[i]))
        {
            s[i] = (s[i] - 65 + k[j % p]) % 26 + 65;
            printf("%c", s[i]);
            j++;
        }
        else if (isalpha(s[i]) && islower(s[i]))
        {
            s[i] = (s[i] - 97 + k[j % p]) % 26 + 97;
            printf("%c", s[i]);
            j++;
        }
        else
        {
            printf("%c", s[i]);
        }
    }
    printf("\n");
}