#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int n, i, j, temp;
    printf("Please Enter the Number of Elements: ");
    scanf("%d", &n);
    int arr[n];
    clock_t start, end;
    for (i = 0; i < n; i++)
        arr[i] = rand();
    start = clock();

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    end = clock();
    double total = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Total time taken by CPU: %lf\n", total);
    return 0;
}