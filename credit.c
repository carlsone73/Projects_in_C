#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    //receiving credit card input
    long long cc_num = get_long_long("Number: ");

    //calculating the length of the credit card number
    int count = log10(cc_num) + 1;

    //adds the second to last digit * 2 to the by_two variable
    long long cc = cc_num;
    int by_two = 0;
    cc = cc / 10;
    int check = (cc % 10) * 2;
    if (check > 9)
    {
        check = 1 + check % 10;
    }
    by_two = by_two + check;

    //loop to add the res of the * 2 numbers
    for (int i = 0; i < count; i += 2)
    {
        cc = cc / 100;
        check = (cc % 10) * 2;
        if (check > 9)
        {
            check = 1 + check % 10;
        }
        by_two = by_two + check;
    }

    //adds the last digit to the by_one variable
    long long cred = cc_num;
    int by_one = 0;
    by_one = by_one + cred % 10;

    //adds the rest of the numbers needed to the by_one variable
    for (int i = 0; i < count; i += 2)
    {
        cred = cred / 100;
        by_one = by_one + cred % 10;
    }

    //creates checksum value
    int checksum = by_two + by_one;

    //creates variables to use for credit card type validation
    int v = cc_num / pow(10, (count - 1));
    int a = cc_num / pow(10, (count - 2));
    int m = cc_num / pow(10, (count - 2));

    //credit card validation
    if (checksum % 10 == 0 && (count == 13 || count == 16) && v % 4 == 0)
    {
        printf("VISA\n");
    }
    else if (checksum % 10 == 0 && count == 15 && (a % 34 == 0 || a % 37 == 0))
    {
        printf("AMEX\n");
    }
    else if (checksum % 10 == 0 && count == 16 && (m % 51 == 0 || m % 52 == 0 || m % 53 == 0 || m % 54 == 0 || m % 55 == 0))
    {
        printf("MASTERCARD\n");
    }
    else
    {
        printf("INVALID\n");
    }

    return 0;
}