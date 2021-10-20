/*
    @author   : Amirul Islam (shiningflash)
    @topic    : Chinese Remainder Theorem
*/

#include <bits/stdc++.h>
using namespace std;

int gcdExtended(int a, int b, int *x, int *y) {
    if (b == 0) {
        *x = 1;
        *y = 0;
        return a;
    }
    int x1, y1;
    int gcd = gcdExtended(b, a % b, &x1, &y1);
    *x = y1;
    *y = x1 - y1 * (a / b);
    return gcd;
}

int modInv(int a, int m) {
    int x, y;
    int gcd = gcdExtended(a, m, &x, &y);
    return ( (x % m + m) % m );
}

int ChineseRemainderTheorem(int N[], int R[], int len) {
    int prod = 1;
    for (int i = 0; i < len; i++) prod *= N[i];

    int result = 0;
    for (int i = 0; i < len; i++) {
        int pp = prod / N[i];
        result += R[i] * pp * modInv(pp, N[i]);
    }
    return result % prod;
}

int main() {
    int N[] = { 5, 7, 8 };
    int R[] = { 3, 1, 6 };
    int len = sizeof(N) / sizeof(N[0]);
    cout << ChineseRemainderTheorem(N, R, len) << endl;
    return 0;
}
