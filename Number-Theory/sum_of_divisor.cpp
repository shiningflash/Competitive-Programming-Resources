/*
    @author : Amirul Islam (shiningflash)
    @date   : July 13, 2020 Monday

    @topic  : Sum of Divisor (Number Theory)

    @hints  :
    * 
    * for 81, sum of divisor = 1 + 3 + 9 + 27 + 81 = 121
    * efficient way: sigma(3^4) = (3^(4+1)) / (3-1) = 242 / 2 = 121
    * 
    * N = p1^e1 x p2^e2 x p3^e3 x ...... x pn^en
    * D(N) = ( ((p1^(e1+1) - 1) / (p1-1)) x ((p2^(e2+1) - 1) / (p2-1)) x ....... x ((pn^(en+1) - 1) / (pn-1))
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;

bool a[N];
int prime[N];

int sieve() {
    int ind = 0, sq = sqrt(N) + 1;
    for (int i = 2; i < sq; i++) {
        if (a[i] == 0) {
            for (int j = 2*i; j < N; j += i) a[j] = 1;
        }
    }
    for (int i = 2; i < N; i++) if (a[i] == 0) prime[ind++] = i;
    return ind; 
}

int sumOfDivisor(int n) {
    int sum = 1, sq = sqrt(n) + 1;
    for (int i = 0; prime[i] < sq; i++) {
        if (n % prime[i] == 0) {
            int p = 1;
            while (n % prime[i] == 0) {
                n /= prime[i];
                p *= prime[i];
            }
            p *= prime[i];
            sum *= ((p - 1) / (prime[i] - 1));
        }
    }
    if (n > 1) {
        int p = n * n;
        sum *= ((p - 1) / (n - 1));
    }
    return sum;
}

int main() {
    // freopen("in", "r", stdin);

    sieve();
    
    int n;
    while (cin >> n) cout << sumOfDivisor(n) << endl;
}
