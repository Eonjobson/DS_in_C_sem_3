#include <stdio.h>
#include <stdlib.h>
#define MAX(x, y) (((x) > (y)) ? (x) : (y))
void main()
{
    int w = 10;
    int n = 4;
    int val[] = {10, 40, 30, 50};
    int wt[] = {5, 4, 6, 3};
    int mat[n + 1][w + 1];
    printf("Entering step 1\n");
    for (int c = 0; c < w + 1; c++)
    {
        mat[0][c] = 0;
    }
    for (int c = 0; c < n + 1; c++)
    {
        mat[c][0] = 0;
    }
    printf("Entering step 2\n");
    for (int item = 1; item <= n; item++)
    {

        for (int capacity = 1; capacity <= w; capacity++)
        {
            // printf("Segmentation here?");
            int maxValWithoutCurr = mat[item - 1][capacity];
            int maxValWithCurrent = 0;
            int weightOfCurrent = wt[item - 1];
            if (capacity >= weightOfCurrent)
            {
                maxValWithCurrent = val[item - 1];
                int remainingCapacity = capacity - weightOfCurrent;
                maxValWithCurrent += mat[item - 1][remainingCapacity];
            }

            mat[item][capacity] = MAX(maxValWithCurrent, maxValWithoutCurr);
        }
    }
    printf("%d is max profit ", mat[n][w]);
}