
#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int ll;

ll bionomialCOEFFICIENT(int n, int k) {
    ll res = 1;
    if (k > (n-k)) k = n-k;
    for (int i = 0; i < k; i++) {
        res *= (n-i);
//        cout << res << endl;
        res /= (i+1);
//        cout << res << endl << endl;
    }
    return res;
}

ll catalan(int n) {
    ll c = bionomialCOEFFICIENT(2*n, n);
    return c/(n+1);
}

int main() {
    for (int i = 0; i <= 51; i++)
        cout << (ll) catalan(i) << endl;
}
