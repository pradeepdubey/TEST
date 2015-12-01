#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#define SIZE 6

void printMatrix(int **arr,int size) 
{

    int i,j;
    for (i=0;i<size;i++) 
    {
        for(j=0;j<size;j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}
int **diagonal(int** A, int n11, int n12, int *len1) {

    int i,j;

    for (i=0; i< SIZE;i++)
    {
        for (j=0;j<=i;j++)
        {
            printf("%3d ", A[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int **arr;

    int i,j,count=0;
    arr  = (int **)malloc(sizeof(int *)*SIZE);
    arr[0] = (int *)malloc(sizeof(int)*SIZE*SIZE);

    for(i = 0; i < SIZE; i++)
            arr[i] = (*arr + SIZE * i);
    for (i=0; i< SIZE;i++)
    {
        for (j=0;j<SIZE;j++)
        {
            arr[i][j] = count++;
             
        }
    }

       
    int M[][SIZE] = {{1, 2, -1, -4, -20,20},
                         {-8, -3, 4, 2, 1,20},
                         {3, 8, 10, 1, 3,20},
                         {-4, -1, 1, 7, -6,30},
                         {-8, -3, 4, 2, 1,20},
                         {-4, -1, 1, 7, -6,30}
                     };
    int len=0;
    //int **sol = diagonal((int **)M , SIZE,SIZE, &len);                   
    printf("Printing M\n");
    printMatrix((int**)M,SIZE);
    printf("Printing Arr\n");
    printMatrix((int**)arr,SIZE);
    return 0;
}
