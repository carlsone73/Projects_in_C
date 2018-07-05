#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    do
    {
        printf("Height: ");
        height = get_int();
    }
    while(height < 0 || height > 23);

    for (int i = 0; i < height; i++)
    {
        printf("%*s", height - i - 1, "");
        printf("#");
        for (int n = 0; n < i + 1; n++)
        {
            printf("#");
        }
        printf("\n");
    }
}