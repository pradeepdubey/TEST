#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#define COL 6
#define ROW 6

int kadane(int a[],int *finish, int n)
{

    int maxSoFar=INT_MIN, sum=0,i;
    int locStart = 0;
    *finish = -1;

    for (i=0;i<n;i++)
    {
        if (a[i] > maxSoFar) {
            maxSoFar = a[i];
            *finish = i;
        }
    }
    return maxSoFar;
}

void printHOurGlass(int arr[][COL],int l,int t)
{
    printf("%3d %3d %3d\n", arr[l-1][t-1], arr[l-1][t], arr[l-1][t+1]);
    printf("    %3d    \n", arr[l][t]);
    printf("%3d %3d %3d\n", arr[l+1][t-1], arr[l+1][t], arr[l+1][t+1]);
       
}
void printMatrix(int arr[][COL],int t,int b,int l,int r) 
{

    int i,j;
    for (i=t;i<b;i++) 
    {
        for(j=l;j<r;j++)
        {
            printf("%3d ", arr[i][j]);
        }
        printf("\n");
    }
}
int  hourGlassSum(int arr[][COL],int l,int t) 
{

    int sum = 0;

    sum = arr[l-1][t-1] + arr[l-1][t] + arr[l-1][t+1] + arr[l][t] + arr[l+1][t-1] + arr[l+1][t] + arr[l+1][t+1];

    return sum;
            
}

void findMaxSum(int arr[][COL])
{
    int temp[ROW],maxSum=INT_MIN,sum;
    int fleft,fright,ftop,fbottom;
    int left =0, top, right =0,i=0,start, finish;

    for (left=1; left < COL-1;++left) 
    {
        memset(temp,0,sizeof(temp));
        temp[0] = INT_MIN;
        temp[ROW-1] = INT_MIN;
        for (top=1;top < ROW-1 ;++top) {
            printHOurGlass(arr,left,top);
            temp[top] = hourGlassSum(arr,left,top);
            printf("Calculated for above HOurGlass at %d,%d Sum is %d\n", left, top, temp[top]);
        }
        sum = kadane(temp,&finish,ROW);
        printf("-----Calculated Maximum for HOurGlass at %d,%d , Sum is %d, MaxSum is %d\n", left, top, sum, maxSum);
        if (sum > maxSum)
        {
            maxSum = sum;
            fleft = left-1;
            fright = left+1;
            ftop = finish-1;
            fbottom = finish+1;
        }
    }
    printf("(Top, Left) (%d, %d)\n", ftop, fleft);
    printf("(Bottom, Right) (%d, %d)\n", fbottom, fright);
    printf("Max sum is: %d\n", maxSum);
    printMatrix(arr,fleft,fright,ftop,fbottom);
}

int main()
{
    int M[ROW][COL] = {{0, -4, -6, 0, -7, -6},
                         {-1, -2, -6, -8, -3, -1},
                         {-8, -4,-2, -8, -8, -6},
                         {-3, -1, -2, -5, -7, -4},
                         {-3, -5, -3, -6, -6, -6},
                         {-3, -6, 0, -8, -6, -7}
                     };
    printMatrix(M,0,ROW,0,COL);
    findMaxSum(M);
    printMatrix(M,0,ROW,0,COL);
    return 0;
}
