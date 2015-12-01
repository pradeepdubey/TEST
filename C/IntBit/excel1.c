#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int power(int x, int y) {
    int res=1;
    while (y > 0 ) {
       res = res*x; 
       y--;
    }
    return res;
}

int titleToNumber(char *A) {

    char *s = A;
    int sum = 0, t=0;
    int len = strlen(A);
    len--;
    while(len >= 0) {

        sum = sum + power(26,t)*(*(s+len) - 'A' + 1);
        t++;
        len--;
    }
    return sum;

}


void main() {

    char str[]= "AB";
    //scanf("%s",&n);
    printf("Valueof %s is %d \n", str, titleToNumber(str));
}
