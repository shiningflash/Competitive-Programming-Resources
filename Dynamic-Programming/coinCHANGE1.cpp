/*************************************
 * Coin Change UVA 674 > DP solution O(n)
 * @author Amirul Islam (shiningflash)
 ************************************/

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

/**Define memory set function**/
#define mem(x,y) memset(x,y,sizeof(x))
#define CLEAR(x) memset(x,0,sizeof(x))

/**Define function and object**/
#define pb push_back
#define Sort(v) sort(v.begin(),v.end())
#define _sort(s, n) sort(s, s+n)
#define sqr(x) ((x)*(x))

/**Define constant value**/
#define le 9999999
#define ERR 1e-9
#define pi (2*acos(0))
#define PI 3.141592653589793

/**Define input**/
#define scanint(a) scanf("%d", &a)
#define scanint2(a, b) scanf("%d %d", &a, &b)
#define scanLLD(a) scanf("%llu", &a)

typedef unsigned long long ll;

using namespace std;

/**********************End*******************/

int a[] = {1, 5, 10, 25, 50};
int t, n, m = 5;

int main() {
    while (scanint(n) != EOF) {
        int dp[n+1];
        mem(dp, 0);
        dp[0] = 1;

        for (int i = 0; i < m; i++)
            for (int j = a[i]; j <= n; j++)
                dp[j] += dp[j-a[i]];

        cout << dp[n] << endl;
    }
    return 0;
}
