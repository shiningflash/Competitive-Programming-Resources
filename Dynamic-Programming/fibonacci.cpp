#include <bits/stdc++.h>
using namespace std;
#define ll long long int

const int mx = 40;

ll fib[mx];

void fibonacci() {
    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i <= mx; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }
}

void print_series() {
    for (int i = 0; i < mx; i++) {
        cout << fib[i] << " ";
    }
    cout << "\n";
}

int main() {
    fibonacci();
    print_series();

    return 0;
}

/*
Output
-
0 1 1 2 3 5 8 13 21 34 55 89 144 233 377 ....
*/
