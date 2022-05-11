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
        // Select the smallest element and place it at the ith position
        for (j = i + 1; j < n; j++)
        { // go through the rest of
            // the array and if there's an element smaller than the element at i
            // swap the elements
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    end = clock();
    double total = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Total time taken by CPU: %lf\n", total);
    return 0;
}