/*
    @author : Amirul Islam (shiningflash)
    @date   : July 13, 2020 Monday

    @topic  : Number of Divisor (Number Theory)

    @hints  :
    * 
    * 48 = 1 x 48 = 2 x 24 = 3 x 16 = 4 x 12, 6 x 8, total divisor = 10
    * efficient way: 2 ^ 4 x 3 ^ 1, from product of power+1, ((4+1) x (1+1)) = 10
    * 
    * N = p1^q1 x p2^q2 x p3^q3 x ...... x pn^qn
    * D(N) = (q1+1) x (q2+1) x (q3+1) x ....... x (qn+1)
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

int numberOfDivisor(int n) {
    int sum = 1, sq = sqrt(n) + 1;
    for (int i = 0; prime[i] < sq; i++) {
        if (n % prime[i] == 0) {
            int c = 0;
            while (n % prime[i] == 0) {
                n /= prime[i];
                c++;
            }
            sum *= (c+1);
        }
    }
    if (n > 1) sum *= 2;
    return sum;
}

int main() {
    // freopen("in", "r", stdin);

    sieve();
    
    int n;
    while (cin >> n) cout << numberOfDivisor(n) << endl;
}
