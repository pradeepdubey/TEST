#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n,i,temp;
    vector<int> arr;
    vector<int>::iterator v;

    cin >> n;
    for (i=0;i<n;i++) {
        cin >> temp;
        arr.push_back(temp);
    }
    v = arr.end();
    v--;
    while (v != arr.begin()) {
        cout << *v;
        v--;
    }
    cout << *v << "\n";

    return 0;
}

