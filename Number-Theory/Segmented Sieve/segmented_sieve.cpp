/*
    @author    : Amirul Islam (shiningflash)
    @algorithm : Segmented Sieve

    @problem   : Prime Generator :: SPOJ - PRIME1 
*/

#include <bits/stdc++.h>
using namespace std;

#define MAX 32000 // for upto 10^9

using ll = long long;
vector <int> primes;

void sieve() {
    bool isPrime[MAX];
    for (int i = 0; i <= MAX; i++) isPrime[i] = true;
    for (int i = 3; i * i <= MAX; i += 2) {
        if (isPrime[i]) {
            for (int j = i*i; j <= MAX; j += i) {
                isPrime[j] = false;
            }
        }
    }
    primes.push_back(2);
    for (int i = 3; i <= MAX; i += 2) {
        if (isPrime[i]) primes.push_back(i);
    }
}

void segmentedSieve(ll l, ll r) {
    bool isPrime[r-l+1];
    for (int i = 0; i < r - l + 1; i++) isPrime[i] = true;
    if (l == 1) isPrime[0] = false;
    for (int i = 0; primes[i] * primes[i] <= r; i++) {
        int currentPrime = primes[i];
        ll base = (l / currentPrime) * currentPrime;
        if (base < l) base += currentPrime;
        for (ll j = base; j <= r; j += currentPrime) {
            isPrime[j-l] = false;
        }
        if (base == currentPrime) isPrime[base-l] = true;
    }
    // print
    for (int i = 0; i < r - l + 1; i++) {
        if (isPrime[i]) cout << (i + l) << endl;
    }
    cout << endl;
}

int main() { 
    // freopen("in", "r", stdin);

    sieve();

    ll t, l, r;
    for (cin >> t; t--; ) {
        cin >> l >> r;
        segmentedSieve(l, r);
    }
    return 0;
}

