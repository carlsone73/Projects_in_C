//This program should be able to crack the password that has been stored as a hash
#define _XOPEN_SOURCE
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>


int main(int argc, string argv[])
{
    //checking that argc is 2
    if (argc != 2)
    {
        return 1;
    }

    //This creates the salt using the first two characters from the hash
    char salt[2] = {argv[1][0], argv[1][1]};

    //checks the first character
    for (int i = 0; i < 57; i++)
    {
        char password[2];
        password[0] = 'A' + i;
        string hash = crypt(password, salt);
        if (strcmp(hash, argv[1]) == 0)
        {
            printf("%s\n", password);
            return 0;
        }
    }
    //checks the second character
    for (int i = 0; i < 57; i++)
    {
        char password[3];
        password[0] = 'A' + i;
        for (int j = 0; j < 57; j++)
        {
            password[1] = 'A' + j;
            string hash = crypt(password, salt);
            if (strcmp(hash, argv[1]) == 0)
            {
                printf("%s\n", password);
                return 0;
            }
        }
    }

    //checks the third character
    for (int i = 0; i < 57; i++)
    {
        char password[4];
        password[0] = 'A' + i;
        for (int j = 0; j < 57; j++)
        {
            password[1] = 'A' + j;
            for (int k = 0; k < 57; k++)
            {
                password[2] = 'A' + k;
                string hash = crypt(password, salt);
                if (strcmp(hash, argv[1]) == 0)
                {
                    printf("%s\n", password);
                    return 0;
                }
            }
        }
    }

    //checks the fourth character
    for (int i = 0; i < 57; i++)
    {
        char password[5];
        password[0] = 'A' + i;
        for (int j = 0; j < 57; j++)
        {
            password[1] = 'A' + j;
            for (int k = 0; k < 57; k++)
            {
                password[2] = 'A' + k;
                for (int l = 0; l < 57; l++)
                {
                    password[3] = 'A' + l;
                    string hash = crypt(password, salt);

                    if (strcmp(hash, argv[1]) == 0)
                    {
                        printf("%s\n", password);
                        return 0;
                    }

                }
            }
        }
    }

    //checks the fifth character
    for (int i = 0; i < 57; i++)
    {
        char password[6];
        password[4] = 'A' + i;
        for (int j = 0; j < 57; j++)
        {
            password[3] = 'A' + j;
            for (int k = 0; k < 57; k++)
            {
                password[2] = 'A' + k;
                for (int l = 0; l < 57; l++)
                {
                    password[1] = 'A' + l;
                    for (int m = 0; m < 57; m++)
                    {
                        password[0] = 'A' + m;
                        string hash = crypt(password, salt);
                        if (strcmp(hash, argv[1]) == 0)
                        {
                            printf("%s\n", password);
                            return 0;
                        }
                    }
                }
            }
        }
    }
}