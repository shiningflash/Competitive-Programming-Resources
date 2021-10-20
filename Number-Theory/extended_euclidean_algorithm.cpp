/*
    @author   : Amirul Islam (shiningflash)
    @topic    : Extended Euclidean Algorithm

    * Most efficient algorithm in finding gcd (a, b)
    * Extended Euclidean algorithm also finds integer coefficients x and y such that:
    * ax + by = gcd(a, b) 
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
    return  gcd;
}

int main() {
    int a = 161, b = 28, x, y;
    cout << gcdExtended(a, b, &x, &y) << endl;
}
