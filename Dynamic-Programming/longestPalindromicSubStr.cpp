// longest Palindromic Sub-String (DP)
// @author :: Amirul Islam (17-07-019)

#include <bits/stdc++.h>
using namespace std;

void printLPS(string s, int start, int maxLen) {
    printf("length : %d\n", maxLen);
    for (int i = start; i < start+maxLen; i++) printf("%c", s[i]);
    printf("\n");
}

// TC - O(N^2) :: SC - O(N^2)
void longestPalindromicSubString(string s) {
    int n = s.length(), maxLen = 1, start = 0;
    bool dp[n][n];
    memset(dp, 0, sizeof(dp));

    // check for sub string of length 1
    for (int i = 0; i < n; i++) dp[i][i] = 1;

    // check for sub-string of lenhgth 2
    for (int i = 0; i < n-1; i++) {
        if (s[i] == s[i+1]) {
            cout << i << " " << s[i] << " " << s[i+1] << endl;
            dp[i][i+1] = 1;
            start = i;
            maxLen = 2;
        }
    }

    // check for sub string of length greater than 2
    for (int k = 3; k <= n; k++) {
        for (int i = 0; i < n-k+1; i++) {
            int j = i+k-1;
            if (dp[i+1][j-1] && s[i] == s[j]) {
                dp[i][j] =  1;
                if (k > maxLen) start = i, maxLen = k;
            }
        }
    }
    printLPS(s, start, maxLen);
}

// TC - O(N^2) :: SC - O(1)
void longestPalSubStr_Efficient(string s) {
    int n = s.length(), start = 0, maxLen = 1, low, high;
    for (int i = 1; i < n; i++) {
        // longest even length palindrome
        // ceter point as i-1, i
        low = i-1, high = i;
        while (low >= 0 && high < n && s[low] == s[high]) {
            if (high - low + 1 > maxLen) start = low, maxLen = high - low + 1;
            low--;
            high++;
        }
        //longest odd palindrome
        // center point as i
        low = i-1; high = i+1;
        while (low >= 0 && high < n && s[low] == s[high]) {
            if (high - low + 1 > maxLen) start = low, maxLen = high - low + 1;
            low--;
            high++;
        }
    }
    printLPS(s, start, maxLen);
}

int main() {
    //string s = "iamaidleman";
    string s = "madam";
    longestPalindromicSubString(s); // SC - O(N^2)
    longestPalSubStr_Efficient(s); // SC - O(1)
    return 0;
}
