#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define R 4
#define C 4
 



void displayMatrix(char *p, int r, int c)
{
int row, col;
char *zPtr;
printf("\n\n");
 
 for(row = 0; row < r; row++)
 {
 zPtr = p + row*c;
 for(col = 0; col < c; col++)
 {
 printf("%c\t", *(zPtr+ col));
 }
 printf("\n");
 }

printf("\n\n");
}
 void spiralPrint(int m, int n, char a[R][C])
 {
 int i, k = 0, l = 0;

/*k - starting row index
m - ending row index
l - starting column index
n - ending column index
i - iterator
*/
 
 while (k < m && l < n)
 {
 /* Print the first row from the remaining rows */
 for (i = l; i < n; ++i)
 {
 printf("%c ", a[k][i]);
 }
 k++;

/* Print the last column from the remaining columns */
for (i = k; i < m; ++i)
{
printf("%c ", a[i][n-1]);
}
n--;
 
 /* Print the last row from the remaining rows */
 if ( k < m)
 {
 for (i = n-1; i >= l; --i)
 {
 printf("%c ", a[m-1][i]);
 }
 m--;
 }

/* Print the first column from the remaining columns */
if (l < n)
{
for (i = m-1; i >= k; --i)
{
printf("%c ", a[i][l]);
}
l++;
}
}
}

bool find_pattern(int m, int n, char matrix[][n], int i, int j, char *pattern, bool visited[][C])
{
static int delta_i[8]={-1, -1, -1, 0, 1, 1, 1, 0};
static int delta_j[8]={1, 0, -1, -1, -1, 0, 1, 1};
int k;
char *p=pattern;
printf("String is %s\n", pattern);
if(*p == '\0') return true;

if(i<0 || i>m-1 || j<0 || j>n-1) return false;
if(matrix[i][j] != *p || visited[i][j]==true) return false;

visited[i][j]=true;
//displayMatrix(matrix,R,C);
for(k=0; k<8; k++) {
   // printf("p to be find next is %s K is %d \n", p+1, k);
 if(find_pattern(m, n, matrix, i+delta_i[k], j+delta_j[k], p+1, visited)==true) 
{//printf("Found Checking First p is %s\n", p+1);
    return true;
    }
}
return (visited[i][j]=false);
}
 


bool pattern_match(int m, int n, char matrix[][n], char *pattern)
 {
 bool visited[R][C];
 bool found=false;
 int i, j,k,l;

 for (i=0;i<m;i++) {
    for(j=0; j<n; j++) visited[i][j]=false;
 }


for(i=0; i<m; i++)  {
    for(j=0; j<n; j++) {
        printf("Main Function Finding pattern %s at i=%d, j=%d\n",pattern, i,j);
        if(find_pattern(m, n, matrix, i, j, pattern, visited)==true) {
        printf("Main Found pattern %s at i=%d, j=%d\n",pattern, i,j);
        found = true;
        break;
        }

        if (found)
            found=false;
    }
        for (k=0;k<m;k++) {
            for(l=0; l<n; l++)
                visited[k][l]=false;
        }

}
return found;
}

 /* Driver program to test above functions */
 int main()
 {
 char a[R][C] = { {'a','f','g','r'},
 {'a','g','e','t'},
 {'a','v','h','p'},
 {'d','b','k','e'}
 };
char *aPtr = (char *)a;
char *str = (char*)malloc(10*sizeof(char));
bzero(str,10);
strncpy(str,"get",3);

displayMatrix(aPtr,R,C);
spiralPrint(R, C, a);
displayMatrix(aPtr,C,R);
displayMatrix(aPtr,R,C);
if (pattern_match(R,C,a,str) == true){
    printf("PAttern found\n");
}
return 0;
}
