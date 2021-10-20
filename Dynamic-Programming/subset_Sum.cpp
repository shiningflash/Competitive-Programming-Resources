#include <bits/stdc++.h>
using namespace std;
#define LLI long long int

const int mx = 1e5+5;

// complexity: exponential
bool isSubsetSumRec(int a[], int n, int sum) {
    if (sum == 0) return true;
    if (n == 0 && sum != 0) return false;
    if (a[n-1] > sum) return isSubsetSumRec(a, n-1, sum);
    return isSubsetSumRec(a, n-1, sum) || // excluding cur element
            isSubsetSumRec(a, n-1, sum-a[n-1]); // including cur element
}

// complexity: Pseudo-polynomial
bool isSubsetSumDP(int a[], int n, int sum) {
    bool subset[n+1][sum+1];
    for (int i = 0; i <= n; i++) subset[i][0] = true;
    for (int i = 0; i <= sum; i++) subset[0][i] = false;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (j < a[i-1]) subset[i][j] = subset[i-1][j];
            else subset[i][j] = subset[i-1][j] || subset[i-1][j-a[i-1]];
        }
    }
    return subset[n][sum];
}

int main() {
    int a[] = {3, 4, 2, 7, 8, 1, 3};
    int len = sizeof(a) / sizeof(a[0]);
    int sum; cin >> sum;
    cout << (isSubsetSumDP(a, len, sum) ? "Subset Found" : "Subset Not found!") << endl;
}
