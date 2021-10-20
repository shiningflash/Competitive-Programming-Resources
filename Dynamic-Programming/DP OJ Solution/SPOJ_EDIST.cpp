#include <bits/stdc++.h>
using namespace std;

int tst, dp[2005][2005];
string s1, s2;

int min(int a, int b, int c) {
    return min(min(a, b), c);
}

int __dp() {
    int n = s1.length(), m = s2.length();
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0) dp[i][j] = j;
            else if (j == 0) dp[i][j] = i;
            else if (s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]);
        }
    }
    return dp[n][m];
}

int main() {
    for (scanf("%d", &tst); tst--;) {
        cin >> s1 >> s2;
        printf("%d\n", __dp());
    }
}
