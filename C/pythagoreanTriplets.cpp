#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

void isTriplet(int arr[], int n)
{
    for (int i=0;i<n;i++) {
        arr[i] = arr[i]*arr[i];
    }

    sort(arr,arr+n);

    for (int i=n-1;i>=2;i--)
    {
        int l=0;
        int r=i-1;

        while (l<r) {
            if (arr[l]+arr[r] == arr[i]) {
                cout <<"Yes Trplets Found";
                cout << "Numbers are: " <<  sqrt(arr[l]) <<"  " << sqrt(arr[r]) << "  " << sqrt(arr[i])<< "\n";
            }
            (arr[l]+arr[r]>arr[i] )? r--:l++;
        }
    } 
}

int main()
{
    int arr[] = {3, 1, 4, 5,10,8,6};
    int arr_size = sizeof(arr)/sizeof(arr[0]);
    isTriplet(arr, arr_size);
    return 0;
}
