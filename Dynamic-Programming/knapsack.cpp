/*                 _
 *  _|_ o._ o._  __|_| _. _|_
 * _>| ||| ||| |(_|| |(_|_>| |
 *               _|
 * @author Amirul islam Al Mamun
 * Knapsack (DP sol) TC - O(n*W)
 */

#include <bits/stdc++.h>
using namespace std;

const int mx = 1e3;

int val[mx], wg[mx], dp[mx];

int knapsack(int N, int W) {
    for (int i = 0; i < N; i++) {
        for (int j = W; j >= wg[i]; j--) {
            dp[j] = max(val[i] + dp[j - wg[i]], dp[j]);
        }
    }
    return dp[W];
}

int main() {
    int N, W;
    cin >> N >> W;
    
    for (int i = 0; i < N; i++) {
        cin >> val[i] >> wg[i];
    }

    cout << knapsack(N, W) << endl;
    return 0;
}
