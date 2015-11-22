#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX 25

void displayMatrix(int p[MAX][MAX], int n)
{
int row, col;
 
 for(row = 0; row < n; row++)
 {
 for(col = 0; col < n; col++)
 {
 printf("%d\t", p[row][col]);
 }
 printf("\n");
 }

}

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    int N, i, j, arr[MAX][MAX],temp,sum1=0,sum2=0;
//    int *aPtr = (int *)arr;

    scanf("%d",&N);
    for (i=0;i<N;i++)
    {
       for (j=0;j<N;j++)
        {
            scanf("%d", &temp);
            arr[i][j] = temp;
        }
    }

    for (i=0;i<N;i++)
        sum1 += arr[i][i];

    for (i=N-1;i>=0;i--) {
        j=N-1-i;
        sum2+=arr[i][j];
   }
    printf("%d", abs(sum1-sum2));
    displayMatrix(arr,N);
    return 0;
}
