// problem link : [http://lightoj.com/volume_showproblem.php?problem=1082]

#include <bits/stdc++.h>
using namespace std;

const int maxn = 100007;
int a[maxn], b[320];
int n, q, len, l, r, tst, t(0);

void processing_decomposed_array() {
    len = (int) sqrt(n);
    len += !(len*len==n);
    for (int i = 0; i < len; i++) b[i] = maxn;
    for (int i = 0; i < n; b[i/len] = min(b[i/len], a[i]), i++);
}

int __sqrt_decomposition() {
    int mn = maxn, left_block = l/len, right_block = r/len;
    if (left_block == right_block) for (int i = l; i <= r; mn = min(mn, a[i++]));
    else {
        for (int i = l, end = (left_block+1)*len-1; i <= end; mn = min(mn, a[i++]));
        for (int i = left_block+1; i < right_block; mn = min(mn, b[i++]));
        for (int i = right_block*len; i <= r; mn = min(mn, a[i++]));
    }
    return mn;
}

int main() {
    //freopen("in", "r", stdin);
    for (scanf("%d", &tst); tst--; ) {
        scanf("%d %d", &n, &q);
        for (int i = 0; i < n; scanf("%d", &a[i]), i++);
        processing_decomposed_array();
        printf("Case %d:\n", ++t);
        while (q--) {
            scanf("%d %d", &l, &r);
            l--; r--;
            printf("%d\n", __sqrt_decomposition());
        }
    }
    return 0;
}
