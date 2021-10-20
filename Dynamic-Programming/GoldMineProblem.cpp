#include <cstdio>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <sstream>
#include <stack>
#include <list>
#include <iostream>
#include <assert.h>

#define mem(x,y) memset(x,y,sizeof(x))
#define CLEAR(x) memset(x,0,sizeof(x))

#define pb push_back
#define Sort(v) sort(v.begin(),v.end())
#define _sort(s, n) sort(s, s+n)
#define sqr(x) ((x)*(x))

#define le 50001
#define ERR 1e-9
#define pi (2*acos(0))
#define PI 3.141592653589793
#define MX 1e18

#define scanint(a) scanf("%d", &a)
#define scanLLD(a) scanf("%lld", &a)

typedef long long ll;
using namespace std;

/* -------------------------- */

int gold[10000][10000];
int dp[10000][10000];

int getMaxGold(int m, int n) {
    for (int i = 0; i < m; dp[i][0] = gold[i][0], i++);
    for (int i = 1; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int right = dp[j][i-1];
            int rightUP = (i == 0) ? 0 : dp[j-1][i-1];
            int rightDN = (i == m-1) ? 0 : dp[j+1][i-1];
            dp[j][i] = gold[j][i] + max(right, max(rightUP, rightDN));
        }
    }
    int sol = dp[m-1][n-1];
    for (int i = 0; i < m; sol = max(sol, dp[i][n-1]), i++);
    return sol;
}

int main() {
    int m, n, x;
    scanf("%d %d", &m, &n);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; scanint(gold[i][j]), j++);
    cout << getMaxGold(m, n) << endl;
}

/*********
4 4
1 3 1 5
2 2 4 1
5 0 2 3
0 6 1 2

 == 16
 ********/
