/*
    @author    : Amirul Islam (shiningflash)
    @problem   : Prime Generator :: SPOJ - PRIME1 
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int check(ll n) {
    if (n == 2 || n == 3) return 1;
    if (n < 2 || n % 2 == 0 || n % 3 == 0) return 0;
    for (ll i = 5; i <= (int) sqrt(n); i += 6) if (n % i == 0 || n % (i + 2) == 0) return 0;
    return 1;
}

int main() {  
    //freopen("in", "r", stdin);
    ll t, n, m;
    for (scanf("%lld", &t); t--; ) {
        scanf("%lld %lld", &m, &n);
        for (ll i = m; i <= n; i++) if (check(i)) printf("%lld\n", i);
        printf("\n");
    }
}
