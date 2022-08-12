#include <stdio.h>
#define MAX(a,b) (((a)>(b))?(a):(b))
void swap(int *a, int *b)
{
    int temp = *a;
    *a= *b;
    *b = temp;
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
