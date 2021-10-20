/*************************************
 * fibonacci > Dynamic Programming
 * tabulation (Bottom up) method
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
#define le 5001
#define ERR 1e-9
#define pi (2*acos(0))
#define PI 3.141592653589793

/**Define input**/
#define scanint(a) scanf("%d",&a)
#define scanLLD(a) scanf("%lld",&a)

typedef unsigned long long ll;

using namespace std;

/**********************End*******************/

ll f[46], t, n;

void fib() {
    f[0] = 0; f[1] = 1;
    for (int i = 2; i <= 45; i++)
        f[i] = f[i-1] + f[i-2];
}

bool solve(int a, int n) {
    int m = 0;
    if (a == 1) return 1;
    for (int i = n; i >= 3; i--) {
        if (a % f[i] == 0) {
            m = solve(a/f[i], i);
            if (m) return 1;
        }
    }
    return 0;
}

int main() {
    fib();
    for (cin >> t; t--; ) {
        cin >> n;
        if (n == 0) cout << "Yes\n";
        else
            if (solve(n, 45)) cout << "Yes\n";
            else cout << "No\n";
    }
    return 0;
}
