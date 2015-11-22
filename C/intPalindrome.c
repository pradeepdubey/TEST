#include <stdlib.h>
#include <stdio.h>

int isOneDigit(int num)
{
    if (num <=9 && num >=0)
        return 1;
    else
        return 0;
}
int palin(int num, int *dnum)
{

    if (isOneDigit(num) == 1)
        return (num == (*dnum)%10);

    if (palin(num/10,dnum) != 1)
        return 0;

    *dnum=*dnum/10;

    return (num % 10 == (*dnum) % 10);
}
int isPalin(int n)
{
int *dnum = (int *)malloc(sizeof(int));

if (n < 0)
    n = n*(-1);
*dnum = n;

return palin(n,dnum);

}

void main()
{
   
    int i, times, num = 0 ;
    scanf("%d",&times);

    for( i=0;i<times;i++) {
        scanf("%d",&num);

        if (isPalin(num)== 1)
            printf("%d is a palindrome\n",num);
        else
            printf("%d is not a palindrome\n",num);
    }
}

