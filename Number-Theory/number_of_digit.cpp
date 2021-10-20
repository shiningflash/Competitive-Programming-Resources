#include <bits/stdc++.h>
using namespace std;

int numberOfDigit(int n) {
    return ( log10(n) + 1 );
}

// D = floor [ log 10 (1) + log 10 (2) + …………… + log 10 (N) ] + 1
int numberOfDigitOfFactorial(int n) {
    int ret = 0;
    for (int i = 1; i <= n; i++) ret += log10(i);
    return ++ret;
}

// D = floor [ log 10 (X Y ) ] + 1 = floor [ Y x log 10 (X) ] + 1
int numberOfDigitOfPower(int x, int y) {
    int ret = y * log10(x);
    return ++ret;
}

int main() {
    int x = 344, y = 12;
    cout << numberOfDigit(x) << endl; // # of digit of x
    cout << numberOfDigitOfFactorial(x) << endl; // # of digit of x!
    cout << numberOfDigitOfPower(x, y) << endl; // # of digit of x^y
}
