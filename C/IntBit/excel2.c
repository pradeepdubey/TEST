#include <stdlib.h>
#include <stdio.h>

char *convertToTitle(int A) {

    int dividend = A;
    char *columnName=(char*)malloc(1024*sizeof(char));
    int modulo;
    char tmp;
    int l=0,r=0;
    char *str = columnName;

    int i=0;
    while (dividend > 0)
    {
        modulo = (dividend - 1) % 26;
        str[i] = (char)(65 + modulo);
        dividend = (int)((dividend - modulo) / 26);
        i++;
    } 
    str[i] = '\0';
    r= i-1;
    str = columnName;
    while (l < r) {
        tmp = str[l];
        str[l] = str[r];
        str[r] = tmp;
        l++;
        r--;
    }
    return columnName;
}


int main() {

    int A;
    scanf("%d", &A);

    printf("The Value is %s \n", convertToTitle(A));
}
