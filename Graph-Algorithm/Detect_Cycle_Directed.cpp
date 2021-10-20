/*
  Detect Cycle in a Directed Graph
  @Complexity - O(N+E)
  @author Amirul islam
                   _
   _|_ o._ o._  __|_| _. _|_
  _>| ||| ||| |(_|| |(_|_>| |
                _|
*/

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

#define le 1000009
#define ERR 1e-9
#define pi (2*acos(0))
#define PI 3.141592653589793

#define scanint(a) scanf("%d", &a)
#define scanLLD(a) scanf("%lld", &a)

typedef long long ll;
using namespace std;

/*--------------**---------------*/

vector <bool> vis;
vector <vector <int> > g;
vector <bool> recStack; // recursion stack
int nodes, edges;

bool isCycleUtil(int v) {
    if (!vis[v]) {
        vis[v] = true;
        recStack[v] = true;
        for (auto i = g[v].begin(); i != g[v].end(); i++) {
            if (!vis[*i] && isCycleUtil(*i)) return true;
            else if (recStack[*i]) return true;
        }
    }
    recStack[v] = false;
    return false;
}

bool isCyclic() {
    vis.assign(nodes, false);
    recStack.assign(nodes, false);
    for (int i = 0; i < nodes; i++)
        if (isCycleUtil(i))
            return true;
    return false;
}

int main() {
    scanf("%d %d", &nodes, &edges);
    g.assign(nodes, vector<int>());

    int u, v;
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        g[u].pb(v);
    }

    if (isCyclic()) printf("Graph contains cycle\n");
    else printf("Graph doesn't contain cycle\n");
    return 0;
}

/*
Input:
 ----
 // 1st line 4 nodes, 6 edges
4 6
0 1
0 2
1 2
2 0
2 3
3 3

Output:
 -----
Graph contains cycle
*/
