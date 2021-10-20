/*************************************
 * Knapsack (recursive solution) O(2^n)
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

int w[] = {10, 20, 30};
int val[] = {60, 100, 120};
int cnt = 0;

int knapsack(int W, int n) {
    cnt++;
    cout << W << " " << n << endl;
    if (n == 0 || W == 0) return 0;
    if (w[n-1] > W) return knapsack(W, n-1);
    else return max(val[n-1] + knapsack(W-w[n-1], n-1), knapsack(W, n-1));
}

int main() {
    int n = 3, W = 50;
    cout << knapsack(W, n) << " " << cnt << endl;
}
