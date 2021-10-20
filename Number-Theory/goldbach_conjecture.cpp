/*
    @author   : Amirul Islam (shiningflash)
    @topic    : Goldbach's Conjecture (Number Theory)
    @theory   : For any integer n (n ≥ 4) there exist two prime numbers p1  and p2  such that p1  + p2 = n.
*/

#include <bits/stdc++.h>
using namespace std;
#define MAX 100000

bool isPrime[MAX];

void sieve() {
    memset(isPrime, true, sizeof(isPrime));
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i*i < MAX; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j < MAX; j += i) isPrime[j] = false;
        }
    }
}

/*
   * The function goldbach_conjecture(n) finds the number of
   * different pairs (p1, p2 ), for which n = p1 + p2.
*/
int goldbach_conjecture(int n) {
    int ret = 0;
    for (int i = 2; i <= n / 2; i++) {
        if (isPrime[i] && isPrime[n-i]) ret++;
    }
    return ret;
}

int main() {
    sieve();

    int n;
    while (cin >> n) cout << goldbach_conjecture(n) << endl;
}
