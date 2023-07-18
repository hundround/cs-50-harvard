#include <cs50.h>
#include <stdio.h>

int n;
int main(void)
{
    // TODO: Have the user input the height
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);
    // We cant really figure this out, so we add 1 to height.

    for (int i = 1; i <= n; i++)
    {
        for (int j = i+1; j <= n; j++) // print space before #
        {
            printf(" ");
        }
        for (int j = 1; j <= i; j++) //print the left half of pyramid
        {
            printf("#");
        }
        printf("  "); // print the space between two pyramids
        for (int j = 1; j <= i; j++) // print the right half of pyramid
        {
            printf("#");
        }
        printf("\n");
    }
}