#include <bits/stdc++.h>
using namespace std;

int n, m, x, t(0);
int dp[25][25], a[25], b[25];

int __dp() { 
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i] == b[j]) dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[n][n];
}

int main() {
//    freopen("in", "r", stdin);
    scanf("%d", &n);
    for (int i = 1; i <= n; scanf("%d", &x), a[x] = i, i++);
    while (~scanf("%d", &x)) {
        b[x] = 1;
        for (int i = 2; i <= n; scanf("%d", &x), b[x] = i, i++);
        printf("%d\n", __dp());
    }
    return 0;
}
