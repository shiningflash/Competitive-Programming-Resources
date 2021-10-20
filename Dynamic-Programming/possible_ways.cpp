/*************************************
 * Alphacode by DP (tebulation method)
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

typedef long long ll;

using namespace std;

/**********************End*******************/

char s[le], c, d;
int a[le], len;

int solve () {
    len = strlen(s);
    a[0] = 1;
    a[1] = 1;
    for (int i = 2; i <= len; i++) {
        a[i] = 0;
        c = s[i-2] - '0';
        d = s[i-1] - '0';
        if (c == 1) a[i] += a[i-2];
        if (c == 2 && d <= 6) a[i] += a[i-2];
        if (d != 0) a[i] += a[i-1];
    }
    return a[len];
}

int main() {
    while (1) {
        cin >> s;
        if (s[0] == '0') break;
        printf("%d\n", solve());
    }
    return 0;
}
