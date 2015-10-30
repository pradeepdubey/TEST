#include <stdlib.h>
#include <stdio.h>

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int l, int h)
{
    int x = arr[h];
    int i = (l-1);
    int j;

    for (j=l; j <= h-1;j++)
    {
        if (arr[j] <= x)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1],&arr[h]);
    return (i+1);
}

void quickSort(int arr[],int l,int h)
{
    if (l < h)
    {
        int p = partition(arr, l, h);
        quickSort(arr,l,p-1);
        quickSort(arr,p+1,h);
    }

}

void printArray(int A[],int size)
{
  int i;
  for (i=0;i<size;i++)
    printf("%d ", A[i]);
  printf("\n");
}

void main()
{
    int arr[] = {12,56,43,456,21,-13,789,12345,-3456,0,786};
    int arr_size = sizeof(arr)/sizeof(arr[0]);

    printf("Given Array is : \n");
    printArray(arr,arr_size);
    quickSort(arr,0,arr_size - 1);
    printf("Sorted Array is : ");
    printArray(arr,arr_size);
}
