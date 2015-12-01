/* Program to find the smallest positive missing number */
#include <stdio.h>
#include <stdlib.h>
 
void printArr(int arr[], int n)
{
    int i=n;
    for (i=0; i < n;i++)
    {
        printf("%d ", arr[i]);
    } 
    printf("\n");
}

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int segregate (int arr[], int size)
{
    printf("In Segregste\n");
    int j = 0, i;
    for(i = 0; i < size; i++)
    {
        if (arr[i] <= 0)
        {
            swap(&arr[i], &arr[j]);
            j++;
        }
        printArr(arr,size);
    }
    return j;
}
 
int firstMissingPositivePositive(int arr[], int size)
{
    int i;
    printf("In Misging First PositivePostive \n");

    for(i = 0; i < size; i++)
    {
        if(abs(arr[i]) - 1 < size && arr[abs(arr[i]) - 1] > 0)
            arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1];
    printArr(arr,size);
    }
 
// Return the first index value at which is positive
    for(i = 0; i < size; i++)
    if (arr[i] > 0)
        return i+1;// 1 is added becuase indexes start from 0
    return size+1;
}
 
 /* Find the smallest positive missing number in an array that contains
 both positive and negative integers */
int firstMissingPositive(int arr[], int size)
{
// First separate positive and negative numbers
    int shift = segregate (arr, size);

 // Shift the array and call firstMissingPositivePositive for
// positive part
    return firstMissingPositivePositive(arr+shift, size-shift);
}

int main()
{
int arr[] = {-3,4,-1,11,1,-2,4,-6,5,14};
int arr_size = sizeof(arr)/sizeof(arr[0]);
printArr(arr,arr_size);
int missing = firstMissingPositive(arr, arr_size);
printArr(arr,arr_size);
printf("The smallest positive missing number is %d ", missing);
getchar();
return 0;
}
