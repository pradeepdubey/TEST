#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int getMaxVehicle(int width[],int l,int r, int n) {
int max=-1;
while (l < r ) {
if (width[l] > max)
max = width[l];
}

switch (max) {
case 3: return 1;
case 2: return 2;
case 1: return 3;
default: return -1;
}
}


int main(){
int n,width_i,a0; 
int t; 
scanf("%d %d",&n,&t);
int width[n];
for( width_i = 0; width_i < n; width_i++){
 scanf("%d",&width[width_i]);
 }
 for(a0 = 0; a0 < t; a0++){
 int i; 
 int j; 
 scanf("%d %d",&i,&j);
 printf("%d\n",getMaxVehicle(width,i,j,n));
 }
 return 0;
 }

