#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
void cutSticks(int arr[], int n){
    int i;
    int size=n,min;
    while (size > 0) { 
        min = INT_MAX;
        size= 0;
        for (i = 0 ; i < n; i++){
            if (arr[i] > 0) {
                if (min > arr[i]) {
                    min = arr[i];

                }
                size++;
            }
        }
        printf("%d\n",size);
        size = 0;
        for (i = 0; i < n;i++) {
            if (arr[i] > 0) {
                arr[i] -= min;
                if (arr[i] > 0 )
                    size++;
            }
        }
    }
}
 int main(){
 int n; 
 scanf("%d",&n);
 int arr[n];
 int arr_i;
 for(arr_i = 0; arr_i < n; arr_i++){
scanf("%d",&arr[arr_i]);
}
cutSticks(arr,n);
return 0;
}

