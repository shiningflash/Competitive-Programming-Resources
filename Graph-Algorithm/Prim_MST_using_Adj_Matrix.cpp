// Prim’s Minimum Spanning Tree (MST)
// Greedy approach, TC - O(n^2) adj. matrix

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
#include <limits>

/**Define memory set function**/
#define mem(x, y) memset(x,y,sizeof(x))
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
#define INT_MAX 2147483647

/**Define input**/
#define scanint(a) scanf("%d",&a)
#define scanLLD(a) scanf("%lld",&a)

typedef long long ll;
using namespace std;

////////////////////////////////////////

const int MX = 10000;
int g[MX][MX];
int dis[MX];
int parent[MX];
bool vis[MX];
int nodes;

inline void printMST() {
    printf("Edge \t cost\n");
    for (int i = 1; i < nodes; i++) {
        printf("%d - %d \t %d\n", parent[i], i, g[i][parent[i]]);
    }
}

inline int minNODE() {
    int min = INT_MAX, minINDEX;
    for (int i = 0; i < nodes; i++) {
        if (!vis[i] && dis[i] < min) {
            min = dis[i], minINDEX = i;
        }
    }
    return minINDEX;
}

inline void prim_MST() {
    for (int i = 0; i < nodes; i++) {
        vis[i] = false, dis[i] = INT_MAX;
    }
    dis[0] = 0;
    parent[0] = -1;
    for (int i = 0; i < nodes-1; i++) {
        int u = minNODE();
        vis[u] = true;
        for (int v = 0; v < nodes; v++) {
            if (g[u][v] && !vis[v] && g[u][v] < dis[v]) {
                parent[v] = u, dis[v] = g[u][v];
            }
        }
    }
    printMST();

}

int main() {
    nodes = 5;
    for (int i = 0; i < nodes; i++)
        for (int j = 0; j < nodes; j++)
            scanf("%d", &g[i][j]);

    prim_MST();
    return 0;
}

/*
0 2 0 6 0
2 0 3 8 5
0 3 0 0 7
6 8 0 0 9
0 5 7 9 0
*/
