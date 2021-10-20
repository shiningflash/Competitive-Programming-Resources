/*************************************
 * UVA - 369 >> bionomial co-efficient
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

ll bioCOEFF(int n, int k) {
    ll res = 1;
    if (k > n-k) k = n-k;
    for (int i = 0; i < k; i++) {
        res *= (n-i);
        res /= (i+1);
    }
    return res;
}

int main() {
    int n, k;
    while (scanf("%d %d", &n, &k)) {
        if (n == 0 && k == 0) break;
        printf("%d things taken %d at a time is %llu exactly.\n", n, k, bioCOEFF(n, k));
    }
    return 0;
}
