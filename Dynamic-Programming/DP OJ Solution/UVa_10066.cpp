#include <bits/stdc++.h>
using namespace std;

int n, m, t(0);
int dp[105][105], a[105], b[105];

int noTiles() {
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i] == b[j]) dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[n][m];
}

int main() {
    while (scanf("%d %d", &n, &m) && n && m) {
        for (int i = 1; i <= n; scanf("%d", &a[i]), i++);
        for (int i = 1; i <= m; scanf("%d", &b[i]), i++);
        printf("Twin Towers #%d\nNumber of Tiles : %d\n\n", ++t, noTiles());
    } 
}
