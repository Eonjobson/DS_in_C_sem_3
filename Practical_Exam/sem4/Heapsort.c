/*
  @Override
  public void sort(int[] values) {
    Heapsort.heapsort(values);
  }

  private static void heapsort(int[] ar) {
    if (ar == null) return;
    int n = ar.length;

    // Heapify, converts array into binary heap O(n), see:
    // http://www.cs.umd.edu/~meesh/351/mount/lectures/lect14-heapsort-analysis-part.pdf
    for (int i = Math.max(0, (n / 2) - 1); i >= 0; i--) {
      sink(ar, n, i);
    }

    // Sorting bit
    for (int i = n - 1; i >= 0; i--) {
      swap(ar, 0, i);
      sink(ar, i, 0);
    }
  }

  private static void sink(int[] ar, int n, int i) {
    while (true) {
      int left = 2 * i + 1; // Left  node
      int right = 2 * i + 2; // Right node
      int largest = i;

      // Right child is larger than parent
      if (right < n && ar[right] > ar[largest]) largest = right;

      // Left child is larger than parent
      if (left < n && ar[left] > ar[largest]) largest = left;

      // Move down the tree following the largest node
      if (largest != i) {
        swap(ar, largest, i);
        i = largest;
      } else break;
    }
  }

  private static void swap(int[] ar, int i, int j) {
    int tmp = ar[i];
    ar[i] = ar[j];
    ar[j] = tmp;
  }
*/
#include <stdio.h>
#define MAX(a,b) (((a)>(b))?(a):(b))
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 
void sink(int arr[],int n,int i){
     while (1) {
      int left = 2 * i + 1; // Left  node
      int right = 2 * i + 2; // Right node
      int largest = i;
      
      // Right child is larger than parent
      if (right < n && arr[right] > arr[largest]) largest = right;

      // Left child is larger than parent
      if (left < n && arr[left] > arr[largest]) largest = left;

      // Move down the tree following the largest node
      if (largest != i) {
        swap(&arr[largest], &arr[i]);
        i = largest;
      } else break;
    }

}
void heapsort(int arr[],int n){
    //Given the array, now we need to perform heapify and sort it 
   for (int i = MAX(0, (n / 2) - 1); i >= 0; i--) {
      sink(arr, n, i);
    }
    // for(int i=0;i<n;i++){
    //     printf("%d ",arr[i]);
    // }
    //We have now constructed our heap 
    for(int i=n-1;i>=0;i--){
        swap(&arr[i],&arr[0]);
        sink(arr,i,0);
    }

} 
void main(){
    int arr[] ={1,3,8,4,5};
    int n =5;
    heapsort(arr,n);
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}