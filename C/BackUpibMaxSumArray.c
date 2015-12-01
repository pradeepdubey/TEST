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
    curSum += A[i];
    if (A[i] < 0)
          neg++;
    if (A[i] == 0)
        zero++;;
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
        if (zero != i)
            s = i + 1;
    }
} 
    if (neg == n1)
        return NULL;
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
int reslen = *end - *start + 1;
int *length_of_array = &reslen;
int * ret = (int *) malloc(sizeof(int) * *length_of_array);
for ( i = *start;i <=*end; i++) {
ret[i] = array[i];
}

return &ret[0];
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
//int arr[] = {-3,-6,7,2,-7,-8,2,3,4};
int arr[] = {0, 0, -1, 0 };
int start, end, maxsum;
int n1 = sizeof(arr)/sizeof(arr[0]);
//maxSumSubArray(arr,n1,&start,&end,&maxsum);
printArr(arr, n1);
//printf("Max Sum is %d, Start is %d and End is %d \n", maxsum, arr[start], arr[end]);
int resLen = 0;
int *resArr = maxSet(arr,n1,&resLen);
printArr(resArr,resLen);
}
