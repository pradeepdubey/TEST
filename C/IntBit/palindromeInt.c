#include <stdlib.h>
#include <stdio.h>

int reverse(int A) {

    int sign=1, rev =0, temp;
    if (A < 0) {
        sign = -1;
        A*=-1;
    }
    if (A == 0)
        return 0;
    temp = A;
    while (temp!=0) {
        if (rev > (INT_MAX / 10) || (rev == (INT_MAX / 10) && digit > (INT_MAX % 10))) {
                            return -1;
        }
        rev = rev*10;
        rev = rev + temp%10;
        temp = temp/10;
    }

    rev = rev*sign;
    return rev;
}
int isPalindrome(int A) {
    if (A < 0)
        return 0;
    int rev=0,temp=A;
    while (temp!=0) {
        rev = rev*10;
        rev = rev + temp%10;
        temp = temp/10;
    }
    if (A == rev)
        return 1;
    else
        return 0;
}
void main() {

    int n = 0;
    scanf("%d",&n);
    if ( isPalindrome(n) == 1)
        printf("It is a palindrome\n");
    else 
        printf("It is not a palindrome\n");
    printf("Rev of %d is %d \n", n, reverse(n));
}
