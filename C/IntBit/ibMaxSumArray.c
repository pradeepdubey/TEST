#include <stdlib.h>
#include <stdio.h>

int* maxSet(int* A, int n1, int *length_of_array) {

/*

 * Sample Code : 

**length_of_array = 1;

 *int * ret = (int *) malloc(sizeof(int) * *length_of_array);

*ret[0] = 1;

 *return ret;

*/

int maxSumSoFar = -2147483648;
int curSum = 0, maxSum;
int a=0, b = 0, s = 0, i = 0;
int sum1= 0, a1=0,b1=0,neg = 0;
int start=0,end=0, maxsum=0,zero=0;

for( i = 0; i < n1; i++ ) { 
    if (A[i] > 0) {
        curSum += A[i];
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
        printf("A is Positive Sum is equal %d, a is %d b is %d\n",maxSumSoFar,a,b);
    } else if (A[i] == 0) { 
        curSum += A[i];
        if (curSum > maxSumSoFar) {
            maxSumSoFar = 0;
            a = s;
            b = i;
        } else if (curSum == maxSumSoFar) {
            a1 = s;
            b1 = i;
        }   
            
        printf("A is Zero Sum is equal %d, a is %d b is %d\n",maxSumSoFar,a,b);
    } else { 
        s = i + 1;
        curSum = 0;
        neg++;
        printf("A is Neg Sum is equal %d, s is %d b is %d\n",maxSumSoFar,a,b);
    }
} 
    if (neg == n1) {
        length_of_array = 0;
        return NULL;
    }
    start = a;
    end = b;
    maxSum = maxSumSoFar;

    if (sum1 == maxSum) {
        printf("Sum is equal %d, s is %d e is %d\n",sum1,A[start],A[end]);
        int diff1 = b1 - a1; 
        int diff = b -a; 
    if (diff1 > diff) {
        start = a1; 
        end = b1; 
        printf("Diff 1 is greteer  %d, s is %d e is %d Diff1 is %d and diff is %d \n",sum1,A[start],A[end],diff1,diff);
    } else if ( diff1 == diff && a1 > a) {
        start = a1; 
        end = b1; 
        printf("a1 > a2  %d, s is %d e is %d Diff1 is %d and diff is %d \n",sum1,A[start],A[end],diff1,diff);
        }
    } 
    *length_of_array = end - start + 1;
    int j=0;
    int * ret = (int *) malloc(sizeof(int) * (*length_of_array));
    for ( i = start;i <=end; i++) {
        ret[j++] = A[i];
    } 

return ret;
}

int maxSubArray( const int *a, int n1)
{

    int maxSumSoFar = -2147483648;
    int curSum = 0;
    int b = 0, s = 0, i = 0;
    int sum1= 0, a1=0,b1=0;
    
    for( i = 0; i < n1; i++ ) {
        curSum += a[i];
        if ( curSum > maxSumSoFar ) {
            maxSumSoFar = curSum;
            //apos = s;
            b = i;
        }
        if( curSum < 0 ) {
            curSum = 0;
            s = i + 1;
        }
    }
    return maxSumSoFar;
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
//int arr[] = {-2,1,-3,4,-1,2,1,-5,4};
int arr[] = {0, 0, -1, 0 };
int start, end, len=0;
int n1 = sizeof(arr)/sizeof(arr[0]);
int *maxsum = maxSet(arr,n1, &len);
printArr(arr, n1);
printArr(maxsum, len);
}
