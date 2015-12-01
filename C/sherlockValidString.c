#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX 100000

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    int N, i=0, j, flag = 0, inpS=0, outS=0,temp,sum1=0,sum2=0;
    char str[MAX],ch;
    char *sptr;
//    int *aPtr = (int *)arr;

    
    int hmap[26] = {0}, val1=0;
    for (i=0;i<26;i++)
        hmap[i] = 0;
    i=0;
    while ((ch = getchar()) != '\n') {
       str[i++] = ch;
    }
    str[i]='\0';
    int len = strlen(str);
    sptr = str;
    int l=0, r = len-1;
    i=0;
    while (str[i] != '\0') {
            (hmap[(int)str[i] - 'a'])++;
            i++;
        }

    for (i=0;i<26;i++) {
        if (hmap[i] != 0) {
            if (!val1)
                val1 = hmap[i];
        } else 
            continue;
        if (hmap[i] != val1) {
            if (abs(hmap[i] - val1) > 1) {
                printf("NO\n");
                return 0;   
            } else {
                if(flag) {
                    printf("NO\n");
                    return 0;   
                } else
                    flag = 1;
            }
        } else
            continue;
    }
    printf("YES");
    return 1;
}
