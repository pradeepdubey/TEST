#include <iostream>
#include<vector>
#include <stdio.h>
#include <iomanip>
using namespace std;

void printMat(vector< vector<int> > &grid)
{

for ( std::vector<std::vector<int> >::size_type i = 0; i < grid.size(); i++ )
{
   for ( std::vector<int>::size_type j = 0; j < grid[i].size(); j++ )
   {
        std::cout <<setw(2) << grid[i][j] << ' ';
   }
        std::cout << std::endl;
   }
} 

vector<vector<int> > diagonal(vector<vector<int> > &A)
{
    int i, j,k,l,m,n;
    int SIZE = A.size();

    vector<vector<int> > sol;
    m=0,n=1;
    for (i=0;i<SIZE;i++) {
        vector<int> row;
        k = 0;
        l = i;
        for (j=0;j<=i;j++) {
            row.push_back(A[k][l]);
            printf("%2d ", A[k][l]);
            k++;
            l--;
        }
        sol.push_back(row);
        printf("\n");
    }

    for (i=1;i<SIZE;i++) {
        vector<int> row;
        l=SIZE-1;
        k=i;
        for (j=SIZE-1;j>=i;j--){
            row.push_back(A[k][l]);
            k++;
            l--;
        }
        sol.push_back(row);
        printf("\n");
    }

    return sol;
}

int main()
{
    int i, j, count;
    int SIZE = 6;
    int r=SIZE,c=SIZE;

    int no_of_cols = SIZE;
    int no_of_rows = SIZE;
    int initial_value = 0;

    vector<vector<int> > matrix;
    matrix.resize(no_of_rows, vector<int>(no_of_cols, initial_value));
    for (i = 0; i <r; i++)
        for (j = 0; j < c; j++)
            matrix[i][j] = ++count;// OR *(*(arr+i)+j) = ++count

    printMat(matrix);
    vector<vector<int> > sol = diagonal(matrix);
    printMat(sol);
 /* Code for further processing and free the 
 dynamically allocated memory */
 /*
 int len=0;
 int **sol = diagonal(arr, SIZE, SIZE, &len);
    printSolMat(sol,len);
*/
 return 0;
 }
