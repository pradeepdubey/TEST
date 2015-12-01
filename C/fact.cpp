#include <iostream>

using namespace std;

int trailingZeroes(int A) {
    long long c,tmp,rem,fact = 1;
    for (c=1;c<A;c++) {
        cout << "Fact is " << fact;
        fact = fact*c;
        }
    c = 0;

    while (tmp == 0) {
        rem = fact%10;
        fact = fact/10;
        c++;
    }
    return c;
}

int main()
{
 int sol = trailingZeroes(9247);
 cout << "SOluyion is " <<  sol;

}
