#include <cs50.h>
#include <stdio.h>

/**
 * problem set 1 - CS50
 * recreates a half-pyramid using hashes (#) and for this,
 * prompts the user the height of the Mario pyramid
 * (it must be a non-negative integer and no greater than 8).
 **/

int main(void)
{
    int h = 0;

    do
    {
        h = get_int("Height: ");
    }
    while (h < 1 || h > 8);

    int k = h - 1;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < h; j++)
        {
            if (j >= k)
            {
                printf("#");
            }
            else
            {
                printf(" ");
            }
        }
        printf("  ");
        for (int l = 0; l <= i; l++)
        {
            printf("#");
        }
        k--;
        printf("\n");
    }
}