#include <bits/stdc++.h>
using namespace std;

int a[3000003][2], _xor[3000003], mn, mx, n, k, t(0), tst;

void insert(int nn) {
    int p(0), id;
    for (int i = 30; i >= 0; i--) {
        id = bool(nn & (1 << i));
        if (!a[p][id]) a[p][id] = ++k;
        p = a[p][id];
    }
}

int findMAX(int nn) {
    int p(0), id, tmp(0);
    for (int i = 30; i >= 0; i--) {
        id = bool(nn & (1 << i));
        if (a[p][!id]) tmp += (1 << i), p = a[p][!id];
        else p = a[p][id];
    }
    return tmp;
}

int findMIN(int nn) {
    int p(0), id, tmp(0);
    for (int i = 30; i >= 0; i--) {
        id = bool(nn & (1 << i));
        if (a[p][id]) p = a[p][id];
        else tmp += (1 << i), p = a[p][!id];
    }
    return tmp;
}

void solve() {
    memset(a, 0, sizeof(a));
    mn = INT_MAX, mx = INT_MIN;
    scanf("%d", &n);
    insert(k=0);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &_xor[i]);
        _xor[i] ^= _xor[i-1];
        mx = max(mx, findMAX(_xor[i]));
        mn = min(mn, findMIN(_xor[i]));
        insert(_xor[i]);
    }
    printf("Case %d: %d %d\n", ++t, mx, mn);
}

int main() {
    for (scanf("%d", &tst); tst--; solve());
}
