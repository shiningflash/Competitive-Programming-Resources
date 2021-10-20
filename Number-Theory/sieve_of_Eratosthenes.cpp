/*
    @author: Amirul Islam
*/

#include <bits/stdc++.h>
using namespace std;

const int mx = 1e5;

int a[mx+4];

// a[0] == 0, prime number
// a[1] == 1, not prime
void sieve() {
    a[0] = a[1] = 1;
    for (int i = 2; i*i <= mx; i++) {
        if (!a[i]) {
            for (int j = i<<1; j <= mx; j+=i) a[j] = 1;
        }
    }
}

int main() {
    //freopen("in", "r", stdin);
    
    sieve();
    int n;
    scanf("%d", &n);
    if (a[n] == 0) printf("%d is Prime number\n", n);
    else printf("%d is Not Prime number\n", n);
    return 0;
}
