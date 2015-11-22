#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX 50

void main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    int N, i, j, inpS=0, outS=0,temp,sum1=0,sum2=0;
    char str[MAX] = "This is the only one";
    char *sptr = str;
//    int *aPtr = (int *)arr;

    
    int hmap[256] = {0};
    for (i=0;i<256;i++)
        hmap[i] = 0;
    int len = strlen(str);
    for (i=0;i<len;i++) {
        printf("%s\n", str);
        if (hmap[*(sptr+inpS)] == 0) {
            printf("%s %d\n", str, i);
            hmap[*(sptr+inpS)] = 1;
            *(sptr+outS) = *(sptr+inpS);
            outS++;
        }
        inpS++;
    }
    *(sptr+outS) = '\0';

    printf("Final String %s\n", str);
}
