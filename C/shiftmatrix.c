#include <stdio.h>
#define R 5 
#define C 4
 
void displayMatrix(int *p, int r, int c)
{
int row, col, *zPtr;
printf("\n\n");
 
 for(row = 0; row < r; row++)
 {
 zPtr = p + row*c;
 for(col = 0; col < c; col++)
 {
 printf("%d\t", *(zPtr+ col));
 }
 printf("\n");
 }
printf("\n\n");
}

void shiftByOne(int a[R][C], int m, int n)
{
    int l,b,t,r,i;

    int *aPtr = (int *)a;
    l = 0, t = 0, b = m -1, r = n-1;
    while ( l < r || t < b) 
    {
        int corner = a[b][l];
        for (i=l; i < r;i++)
            a[b][i]=a[b][i+1];

        for(i=b;i>t;i--)
            a[i][r]=a[i-1][r];

        for (i=r; i > l ;i--)
            a[t][i]=a[t][i-1];

        for(i=t;i<b;i++)
            a[i][l]=a[i+1][l];
        a[b-1][l] = corner;
     l=l+1;
     r= r-1;
     t=t+1;
     b=b-1;
     //printf("Printing in the Shift Function L=%d, R=%d, T=%d, B=%d\n", l,r,t,b);
     //displayMatrix(aPtr,R,C);
    }  
}
 
void shiftByN(int a[R][C],int r,int c,int n)
{
    int i;
    for (i=0;i<n;i++)
        shiftByOne(a,r,c);

}
 /* Driver program to test above functions */
int main()
{
    int n = 1;
    int a[R][C] = { {1,2,3,4},
                    {13, 14, 15, 16},
                    {23, 24, 25, 26},
                    {33, 34, 35, 36},
                    {43, 44, 45, 46}
                   };

    printf("ENter the number of times to rotate\n");
    scanf("%d", &n);
    int *aPtr = (int *)a;
    displayMatrix(aPtr,R,C);
    shiftByN(a,R,C,n);
    displayMatrix(aPtr,R,C);
    return 0;
}
