// @author: Amirul Islam

#include <bits/stdc++.h>
using namespace std;
#define LLI long long int
#define PII pair <int, int>

const int mx = 1e4;
int dp[mx][mx];

int nCr(int n, int r) {
    if (r == 1) return n;
    if (n == r) return 1;
    if (dp[n][r] != -1) return dp[n][r];
    return dp[n][r] = nCr(n-1, r) + nCr(n-1, r-1);
} 

int main() {
    int n, r;
    cin >> n >> r;
    for (int i = 0; i < mx; i++) {
        for (int j = 0; j < mx; j++) dp[i][j] = -1;
    }
    cout << nCr(n, r) << endl;
}
