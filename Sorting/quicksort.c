#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void sort(int nums[], int low, int hi)
{
    if (low >= hi)
    {
        return;
    }

    int s = low;
    int e = hi;
    int m = s + (e - s) / 2;
    int pivot = nums[m];

    while (s <= e)
    {

        // as long as the element at start position is less than pivot
        // increment start index
        while (nums[s] < pivot)
        {
            s++;
        }
        // as long as element at end index is greater than pivot
        // decrement end index
        while (nums[e] > pivot)
        {
            e--;
        }
        // Now the 2 pointers are at the indexes which don't satisfy the condition
        // swap the elements
        if (s <= e)
        {
            int temp = nums[s];
            nums[s] = nums[e];
            nums[e] = temp;
            s++;
            e--;
        }
    }

    // pivot is now at correct index,sort the two halves
    sort(nums, low, e);
    sort(nums, s, hi);
}
void main()
{
    int n;
    printf("Enter size of array\t");
    scanf("%d", &n);
    int arr[n];
    clock_t start, end;
    for (int i = 0; i < n; i++)
        arr[i] = rand();
    start = clock();
    sort(arr, 0, n - 1);
    end = clock();
    double total = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Total time taken by CPU: %lf\n", total);
}