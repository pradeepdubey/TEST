#include <stdlib.h>
#include <stdio.h>

int *maxSumSubArray( int *array, int n1, int *start, int *end, int *maxSum )
{
    int maxSumSoFar = -2147483648;
    int curSum = 0;
    int a=0, b = 0, s = 0, i = 0;
    int sum1= 0, a1=0,b1=0;
    for( i = 0; i < n1; i++ ) {
        curSum += array[i];
        if ( curSum > maxSumSoFar ) {
            maxSumSoFar = curSum;
            a = s;
            b = i;
        } else if (curSum == maxSumSoFar)
        {
            a1 = s;
            b1 = i;
            sum1 = curSum;
        }
        if( curSum < 0 ) {
            curSum = 0;
            s = i + 1;
        }
    }
    *start = a;
    *end = b;
    *maxSum = maxSumSoFar;
    if (sum1 == *maxSum) {
        int diff1 = b1 - a1;
        int diff = b -a;
            
        if (diff1 > diff) {
            printf("A1 is %d and B1 is %d\n",array[a1],array[b1]);
            *start = a1;
            *end = b1;
        } else if ( diff1 == diff && a1 > a) {
            *start = a1;
            *end = b1;
        }
    }
    int reslen = *end - *start;
    int *length_of_array = &reslen;
    int * ret = (int *) malloc(sizeof(int) * *length_of_array);
    for ( i = *start;i <=*end; i++) {
        ret[i] = array[i];
    }

    return ret;
}

printArr(int arr[], int n)
{
    int i=n;
    for (i=0; i < n;i++)
    {
        printf("%d ", arr[i]);
    }   
    printf("\n");
}
void main()
{
    int arr[] = {-3,-6,7,2,-7,-8,2,3,4};
    int start, end, maxsum;
    int n1 = sizeof(arr)/sizeof(arr[0]);
    maxSumSubArray(arr,n1,&start,&end,&maxsum);
    printArr(arr, n1);
    printf("Max Sum is %d, Start is %d and End is %d \n", maxsum, arr[start], arr[end]);
}
