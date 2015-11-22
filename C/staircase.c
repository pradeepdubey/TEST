#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
        int num=0,i=0,j=0;
        scanf("%d", &num);
        for (i = 0; i < num; i++) 
        {
            for (j = i; j < num-1; j++) 
            {
                 printf(" ");
            }   
            for (j = i; j>=0; j--) 
            {
                printf("X");
            }   
            printf("\n");
        }
        return 0;

}
