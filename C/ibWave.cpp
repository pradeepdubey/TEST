#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

int printArr(vector <int> A)
{
for (int i=0; i < A.size();i++)
{
    printf("%d ", A[i]);
} 
printf("\n");
}

vector<int> wave(vector<int> &A) {
    
    int i = 0;
    vector <int> sol;
    sort (A.begin(), A.end());
    printArr(A);
    if (A.size() == 1) {
        sol.push_back(A[i]);
        return sol;
    }
    for (i = 0 ; i < A.size();i++)
    {

    if (i%2 == 0) {
        if (i != A.size() -1)
            sol.push_back(A[i+1]);
        else
            sol.push_back(A[i]);
    } else
        sol.push_back(A[i-1]);
    }   

    return sol;
}
int main()
{

    int myints[] = {5,1,3,2,4};
    int size = sizeof(myints) / sizeof(int);
    vector<int> Arr (myints, myints + size );
    printArr(Arr);

    vector<int> sol = wave(Arr);
    printArr(sol);
    

    //vector <int> sol = wave(Arr);
//int arr[] = {-2,1,-3,4,-1,2,1,-5,4};
return 1;
}
