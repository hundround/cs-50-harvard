#include <cs50.h>
#include <stdio.h>

int k;

int year_compute();
int main(void)
{
    int i, j;
    // TODO: Prompt for start size
    do
    {
        i = get_int("Start size: ");
    }
    while (i < 9);
    // TODO: Prompt for end size
    do
    {
        j = get_int("End size: ");
    }
    while (j < i);
    // TODO: Calculate number of years until we reach threshold
    k = year_compute(i,j);
    
    // TODO: Print number of years
    printf("Years: %d\n", k);
}

int year_compute(int i,int j)
{
    if (i == j)
    {
        return 0;
    }
    do
    {
        i = i + i/3 - i/4;
        k++;
    }
    while (i < j);
    return k;
}