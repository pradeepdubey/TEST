#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#define COL 5
#define ROW 4

int kadane(int a[],int *start,int *finish, int n)
{

    int maxSoFar=INT_MIN, sum=0,i;
    int locStart = 0;
    *finish = -1;

    for (i=0;i<n;i++)
    {
        sum += a[i];
        if (sum < 0) {
            sum = 0;
            locStart = i+1;
        } else if (sum > maxSoFar) {
            maxSoFar = sum;
            *finish = i;
            *start = locStart;
        }
   }

    if (*finish != -1)
        return maxSoFar;

    maxSoFar = a[0];
    *start = *finish = 0;
    // Find the maximum element in array
    for (i = 1; i < n; i++)
    {
        if (a[i] > maxSoFar)
        {
            maxSoFar = a[i];
            *start = *finish = i;
        }
    }
    return maxSoFar;
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
void findMaxSum(int arr[][COL])
{
    int temp[ROW],maxSum=INT_MIN,sum;
    int fleft,fright,ftop,fbottom;
    int left =0, right =0,i=0,start, finish;

    for (left = 0; left < COL;++left) 
    {
        memset(temp,0,sizeof(temp));
        for (right=left;right < COL;++right)
        {
            for (i=0;i<ROW;++i)
                temp[i] += arr[i][right];
            sum = kadane(temp,&start,&finish,ROW);
            if (sum > maxSum)
            {
                maxSum = sum;
                fleft = left;
                fright = right;
                ftop = start;
                fbottom = finish;
           }
       }
    }
    printf("(Top, Left) (%d, %d)\n", ftop, fleft);
    printf("(Bottom, Right) (%d, %d)\n", fbottom, fright);
    printf("Max sum is: %d\n", maxSum);
    printMatrix(arr,fleft,fright,ftop,fbottom);
}

int main()
{
    int M[ROW][COL] = {{1, 2, -1, -4, -20},
                         {-8, -3, 4, 2, 1},
                         {3, 8, 10, 1, 3},
                         {-4, -1, 1, 7, -6}
                     };
    findMaxSum(M);
    printMatrix(M,0,ROW,0,COL);
    return 0;
}
