// Longest Palindromic Subsequence (DP) :: TC - O(N^2)
// @author :: Amirul Islam (SUN 14-07-2019 :: 2:49 AM)

#include <bits/stdc++.h>
using namespace std;

// Naive Recursive Implementation
int L(string s, int i, int j) {
    if (i == j) return 1;
    if (s[i] == s[j]) {
        if (i+1 == j) return 2;
        else return 2 + L(s, i+1, j-1);
    }
    else return max(L(s, i+1, j), L(s, i, j-1));
}

/*

dp[][] ::  for"TURBOVENTILATOR"
-------------------------------

1 1 1 1 1 1 1 1 3 3 3 3 3 5 7 
0 1 1 1 1 1 1 1 1 1 1 1 3 5 7 
0 0 1 1 1 1 1 1 1 1 1 1 3 5 7 
0 0 0 1 1 1 1 1 1 1 1 1 3 5 5 
0 0 0 0 1 1 1 1 1 1 1 1 3 5 5 
0 0 0 0 0 1 1 1 1 1 1 1 3 3 3 
0 0 0 0 0 0 1 1 1 1 1 1 3 3 3 
0 0 0 0 0 0 0 1 1 1 1 1 3 3 3 
0 0 0 0 0 0 0 0 1 1 1 1 3 3 3 
0 0 0 0 0 0 0 0 0 1 1 1 1 1 1 
0 0 0 0 0 0 0 0 0 0 1 1 1 1 1 
0 0 0 0 0 0 0 0 0 0 0 1 1 1 1 
0 0 0 0 0 0 0 0 0 0 0 0 1 1 1 
0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 
0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 

lps sequence :: "ROTATOR"

*/

// DP Solution :: TC - O(N^2) :: SC - O(N^2)
int lps_2D(string s, int n) {
    int dp[n][n];
    for (int i = 0; i < n; i++) dp[i][i] = 1;
    for (int cell = 2; cell <= n; cell++) {
        for (int i = 0; i < n-cell+1; i++) {
            int j = i+cell-1;
            if (s[i] == s[j] && cell == 2) dp[i][j] = 2;
            else if (s[i] == s[j]) dp[i][j] = dp[i+1][j-1] + 2;
            else dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
        }
    }
    return dp[0][n-1];
}

// Most efficient one *** ///////////////
// DP Solution :: TC - O(N^2) :: SC - O(N)
int lps_1D(string s, int n) {
    int dp[n];
    for (int i = n-1; i >= 0; i--) {
        int back_up = 0;
        for (int j = i; j < n; j++) {
            if (i == j) dp[j] = 1;
            else if (s[i] == s[j]) {
                dp[j] = back_up + 2;
                back_up = dp[j] - 2;
            }
            else {
                back_up = dp[j];
                dp[j] = max(dp[j-1], dp[j]);
            }
        }
    }
    return dp[n-1];
}

int main() {
    string s = "TURBOVENTILATOR";
    //cout << lps_2D(s, s.size()) << endl;
    cout << lps_1D(s, s.size()) << endl;
}
