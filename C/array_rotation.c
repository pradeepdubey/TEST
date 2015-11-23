#include <stdio.h>
#include <stdlib.h>

int get_rot(int arr[], int size)
{


    int l=0,r=size-1, m;

    while (arr[l] > arr[r]) {
        m = l + (r-l)/2;
        printf("L:%d, M%d, R:%d\n",l,m,r);
        if (arr[r] < arr[m])
            l = m+1;
        else
            r = m;
    }
    return l;
}
void main() {

    int arr[] = {4,5,5, 6,8,9,14,15,1};

    int rot = get_rot(arr,(sizeof(arr)/sizeof(arr[0])));

    printf("Ratation is at value %d\n", rot);

}
