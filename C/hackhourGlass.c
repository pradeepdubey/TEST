#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;


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
        std::fill_n(temp,ROW,0);
        for (top=1;top < ROW-1 ;++top)
            temp[top] = hourGlassSum(arr,left,top);
       
        sum = kadane(temp,&finish,ROW);
        //printf("Calculated for HOurGlass at %d,%d , Sum is %d, MaxSum is %d\n", left, top, sum, maxSum);
        if (sum > maxSum)
        {
            maxSum = sum;
            fleft = left-1;
            fright = left+1;
            ftop = finish-1;
            fbottom = finish+1;
        }
    }
    cout << maxSum;
}

int main()
{
    int M[ROW][COL];
    int i;
    for (i=0;i<ROW;i++) 
    {
      cin >> M[i][0] >> M[i][1] >> M[i][2] >> M[i][3] >> M[i][4] >> M[i][5];
       
    }
    findMaxSum(M);
    return 0;
}
