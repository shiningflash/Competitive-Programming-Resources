/*
    @author   : Amirul Islam (shiningflash)
    @topic    : Fermat's Little Thorem
*/

#include <bits/stdc++.h>
using namespace std;

/*
    @problem     : (x)^p % m
    @complexity  : O(log2(p))
*/
int big_mod(int x, int p, int m) {
    if (p == 0) return 1;
    if (p & 1) return ((x % m) * big_mod(x, p - 1, m)) % m;
    else {
        int ret = big_mod(x, p >> 1, m);
        return ((ret % m) * (ret % m)) % m;
    }
}

// @pre-requisite: m must be prime
// a^(-1) ≡ a^(m-2) (mod m)
void fermats_theorem(int a, int m) {
    if (__gcd(a, m) != 1) {
        cout << "Modular Multiplicative Invrese does not exist." << endl;
    }
    else {
        // modulo inverse is a^(m-2) mode m 
        cout << "Modular Multiplicative Invrese is " << big_mod(a, m - 2, m) << endl;
    }
}

int main() {
    int a = 3, m = 11;
    fermats_theorem(a, m);
}
