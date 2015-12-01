#include <stdio.h>
#include <stdlib.h>

#define SIZE 3
void printMat(int **arr, int size)
{

    int i, j;
    for (i = 0; i <size; i++) {
        for (j = 0; j < size; j++)
            printf("%2d ", arr[i][j]);
        printf("\n");
    }
} 

void printSolMat(int **arr, int size)
{

    int i, j;
    for (i = 0; i <size; i++) {
        if (i <= size/2) {
            for (j = 0; j <i+1; j++)
                printf("%2d ", arr[i][j+1]);
            printf("\n");
        } else {
            for (j = 0; j <2*SIZE-i-1; j++)
                printf("%2d ", arr[i][j+1]);
            printf("\n");
        }
    }
} 

int **diagonal(int** A, int n11, int n12, int *len1)
{
    int i, j,k,l,m,n;

    int **sol = (int **)malloc((2*SIZE-1) * sizeof(int *));

    m=0,n=1;
    for (i=0;i<SIZE;i++) {
        k = 0;
        l = i;
        sol[m] = (int*)malloc((i+1+1)*sizeof(int));
        sol[m][0] = i+1;
        for (j=0;j<=i;j++) {
            sol[m][n++] = A[k][l];
            printf("%2d ", A[k][l]);
            k++;
            l--;
        }
        m++;
        n=1;
        printf("\n");
    }

    for (i=1;i<SIZE;i++) {
        l=SIZE-1;
        k=i;
        sol[m] = (int*)malloc((SIZE-i+1)*sizeof(int));
        sol[m][0] = i+1;
        n=1;
        for (j=SIZE-1;j>=i;j--){
            printf("%2d ", A[k][l]);
            sol[m][n++] = A[k][l];
            k++;
            l--;
        }
        m++;
        printf("\n");
    }

    *len1 = 2*SIZE -1;
    return sol;

}

int main()
{
    int i, j, count;
    int r=SIZE,c=SIZE;
    int **arr = (int **)malloc(r * sizeof(int *));
    for (i=0; i<r; i++)
        arr[i] = (int *)malloc(c * sizeof(int));

// Note that arr[i][j] is same as *(*(arr+i)+j)
    count = 0;
    for (i = 0; i <r; i++)
        for (j = 0; j < c; j++)
            arr[i][j] = ++count;// OR *(*(arr+i)+j) = ++count

    printMat(arr,SIZE);
 /* Code for further processing and free the 
 dynamically allocated memory */
 int len=0;
 int **sol = diagonal(arr, SIZE, SIZE, &len);
    printSolMat(sol,len);

 return 0;
 }
