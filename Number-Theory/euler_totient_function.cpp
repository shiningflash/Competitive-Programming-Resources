/*
    @author   : Amirul Islam (shiningflash)
    @topic    : Euler's Totient Function (Number Theory)
    @theory   : The number of positive integers, not greater than n, and relatively prime with n
*/

#include <bits/stdc++.h>
using namespace std;

int phi(int n) {
    int ret = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0) n /= i;
            ret -= (ret / i);
        }
    }
    if (n > 1) ret -= (ret / n);
    return ret;
}

int main() {
    int n;
    while (cin >> n) cout << phi(n) << endl;
}
