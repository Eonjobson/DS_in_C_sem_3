#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void merge(int arr[],int low,int mid,int high)
{
 int n1=mid-low+1;
 int n2=high-mid;
 int left[n1],right[n2];
 for(int i=0;i<n1;i++)
 left[i]=arr[low+i];
 for(int j=0;j<n2;j++)
 right[j]=arr[mid+1+j];
 int i=0,j=0,k=low;
 while(i<n1 && j<n2)
 {
 if(left[i]<=right[j])
 {
 arr[k]=left[i];
 i++;k++;
 }
 else
 {
 arr[k]=right[j];
 j++;k++;
 }
 }
 while(i<n1)
 {
 arr[k]=left[i];
 i++;k++;
 }
 while(j<n2)
 {
 arr[k]=right[j];
 j++;k++;
 }
}
void merge_sort(int arr[],int l,int r)
{
 if(r>l)
 {
 int m=l+(r-l)/2;
 merge_sort(arr,l,m);
 merge_sort(arr,m+1,r);
 merge(arr,l,m,r);
 }
}
int main()
{
 int n;
 clock_t start,end;
 printf("Enter the number of elements :");
 scanf("%d",&n);
 int arr[n];
 for(int i=0;i<n;i++)
 arr[i]=rand();
 start=clock();
 merge_sort(arr,0,n-1);
 end=clock();
 double total=(double)(end-start)/CLOCKS_PER_SEC;
 printf("\nTotal time for execution is :%lf",total);
}