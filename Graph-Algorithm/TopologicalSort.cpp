/*
      __topological sort__
      __similiar to DFS, just need an extra stack
      __Complexity O(V+E)
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
stack <int> s;
int nodes, edges;

void printStack() {
    for (int i = 0; i < nodes; i++) {
        cout << s.top() << " ";
        s.pop();
    }
}

void topologicalSortUtil(int v) {
    vis[v] = true;
    for (auto i = g[v].begin(); i != g[v].end(); i++)
        if (!vis[*i]) topologicalSortUtil(*i);
    s.push(v);
}

void topologicalSort() {
    vis.assign(nodes, false);
    for (int i = 0; i < nodes; i++)
        if (!vis[i]) topologicalSortUtil(i);
}

int main() {
    scanf("%d %d", &nodes, &edges);
    g.assign(nodes, vector<int>());

    int u, v;
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        g[u].pb(v);
    }

    topologicalSort();
    printStack();
    return 0;
}

/*
    6 6

    5 2
    5 0
    4 0
    4 1
    2 3
    3 1

    topological sort: 5 4 2 3 1 0
*/
