/*************************************************
 * The Legendry Coin Change Problem CodeChef - CTY2
 * @author Amirul Islam (shiningflash) >> DP O(n)
 *************************************************/

#include <bits/stdc++.h>
using namespace std;

const int mx = 1e3;

int coin[mx], dp[mx];

int coin_change_way(int unit, int type) {
    dp[0] = 1;
    for (int i = 0; i < type; i++) {
        for (int j = coin[i]; j <= unit; j++) {
            dp[j] += dp[j - coin[i]];
        }
    }
    return dp[unit];
}

int main() {
    // freopen("in", "r", stdin);

    int unit, type;
    cin >> unit >> type;
    for (int i = 0; i < type; i++) {
        cin >> coin[i];
    }
    cout << coin_change_way(unit, type) << endl;
    return 0;
}

/*
Input:
4 3
1 2 3

Output:
4

Explanation
{1, 1, 1, 1}
{1, 1, 2}
{2, 2}
{1, 3}
*/
