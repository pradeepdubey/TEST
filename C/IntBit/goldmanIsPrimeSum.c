#include <stdlib.h>
#include <stdio.h>

int isPrime(int A) {
    int i;
    if (A == 2) 
        return 1;
    for (i = 2; i <= A / 2; i++) {
        if (A % i == 0)
            return 0;
    }
    return 1;
}

int checkPow(int A, int i) {

    while (A%i == 0)
        A = A /i;

    return (A == 1);
}
int isPower(int A){

    int i, j;

    for (i=2; i <= A/2; i++) {
        if (checkPow(A,i) == 1)
            return 1;
    }
    return 0;

}

int* primesum(int A, int *len1) {
    int i=0, j=0;

    if (A%2 != 0 && A < 2) {
        *len1 = 0;
        return NULL;
    }
    int *a = (int*)malloc(10*sizeof(int));
    for (i = 2; i <= A / 2; i++) {
        if (isPrime(i) && isPrime(A - i)) {
            a[j] = i;
            a[j+1] = A-i;
    printf("Is Prime Num are  %d and  %d \n", a[j], a[j+1]);
            j = j + 2;
    *len1 = j+1;
    return a;
        }
    }
    *len1 = j+1;
    return a;
}

void main() {

    int n = 0;
    scanf("%d",&n);

    int a,b;
    int len=0;
 //   int *ans = primesum(n, &len);

  //  if (ans)
 printf("Num can be fitted %d  \n", isPower(n));
 //scanf("%d %d", &a, &b);
// printf("Num can be fitted %d  \n", checkPow(a,b));


}
