#include <stdio.h>
#include <cs50.h>
#include <math.h>

int min_value(int L, int G, int C);
void print(void);

int main(void)
{
    int L = get_int("Lunatics: \n");
    int G = get_int("Guards: \n");

    for (i = 0; i < L; i++)
    {
        int C[i] = get_int("Craziness level for Lunatic %i: \n", i + 1);
    }

    min_value(L, G, C);
    print();
}

int min_value(int L, int G, int C)
{
    for (i = 0; i < L; i++)
    {
        for (j = 0; j < i + 1; j++)
        {
            if (C[j] > C[i])
            {
                int K = C[j];
                C[j] = C[i];
                C[i] = K;
            }
        }
    }

    int H = G;

    G = round(G / 2);
    for (j = 0; j < G; j++)
    {
        F += C[j];
    }

    if (F < C[G + 1])
    


}