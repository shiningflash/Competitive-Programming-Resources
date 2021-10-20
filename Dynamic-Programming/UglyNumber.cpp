/*************************************
 * Ugly Numbers > UVa - 136
 * solved by - (DP) Dynamic Programming
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

typedef unsigned long ll;

using namespace std;

/**********************End*******************/

ll min3(ll a, ll b, ll c) {
    return min(min(a, b), c);
}

ll getUGLY(int n) {
    ll ugly[n], nxtUGLY = 1;
    ll i2 = 0, i3 = 0, i5 = 0;
    ll mul2 = 2, mul3 = 3, mul5 = 5;
    ugly[0] = 1;

    for (ll i = 1; i < n; i++) {
        nxtUGLY = min3(mul2, mul3, mul5);
        ugly[i] = nxtUGLY;

        if (nxtUGLY == mul2) i2++, mul2 = ugly[i2] * 2;
        if (nxtUGLY == mul3) i3++, mul3 = ugly[i3] * 3;
        if (nxtUGLY == mul5) i5++, mul5 = ugly[i5] * 5;
    }
    return nxtUGLY;
}

int main() {
    cout << "The 1500'th ugly number is " << (ll) getUGLY(1500) << ".\n";
    return 0;
}
