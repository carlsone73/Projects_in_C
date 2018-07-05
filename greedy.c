#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    printf("O hai! ");
    float change;
    do
    {
        printf("How much change is owed?\n");
        change = get_float();
    }
    while(change < 0);

    change = roundf(change * 100);

    int i = (int)change;

    int coins = 0;

    while (i > 24)
    {
        coins = coins + 1;
        i = i - 25;
    }
    while (i > 9)
    {
        coins = coins + 1;
        i = i - 10;
    }
    while (i > 4)
    {
        coins = coins + 1;
        i = i - 5;
    }
    while (i > 0)
    {
        coins = coins + 1;
        i = i - 1;
    }
    printf("%i\n", coins);
}