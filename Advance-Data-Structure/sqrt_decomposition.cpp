// sqrt decomposition
// @author: Amirul Islam

#include <bits/stdc++.h>
using namespace std;

void getsum(int a[], int n, int b[], int m, int l, int r) {
    int sum = 0, lb = l/m, rb = r/m;
    if (lb == rb) for (int i = l; i <= r; sum += a[i++]);
    else {
        for (int i = l, end = (lb+1)*m-1; i <= end; sum += a[i++]);
        for (int i = lb+1; i < rb; sum += b[i++]);
        for (int i = rb*m; i <= r; sum += a[i++]);
    }
    //for (int i = 0; i < m; i++) cout << b[i] << " "; cout << endl;
    printf("%d\n", sum);
}

void sqrt_decomposition(int a[], int n) {
    int m = sqrt(n), q, l, r;
    m += !(m*m == n);
    int b[m];
    memset(b, 0, sizeof(b));
    for (int i = 0; i < n; i++) b[i/m] += a[i];

    for (scanf("%d", &q); q--; ) {
        scanf("%d %d", &l, &r);
        getsum(a, n, b, m, l, r);
    }
}

int main() {
    //freopen("in", "r", stdin);
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    sqrt_decomposition(a, n);
}

/*
---------
INPUT:
9
1 1 1 2 2 2 3 3 3
3
1 3
8 8
0 8
---------
OUTPUT:
4
3
18
---------
*/
