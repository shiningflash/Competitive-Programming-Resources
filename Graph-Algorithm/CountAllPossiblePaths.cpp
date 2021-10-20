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
#include <unordered_set>

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
#define MX 1e9

#define scanint(a) scanf("%d", &a)
#define scanLLD(a) scanf("%lld", &a)

typedef long long ll;
using namespace std;

/* -------------------------- */

void countAllPaths(int u, int d, list<int> *adj, vector <bool> visited, int &totalPaths) {
    visited[u] = true;
    if (u == d) totalPaths++; // current vertex same as destination
    else {
        for (auto i = adj[u].begin(); i != adj[u].end(); i++)
            if (!visited[*i]) countAllPaths(*i, d, adj, visited, totalPaths);
    }
    visited[u] = false;
}

int countPaths(int nVertex, list<int> *adj, int s, int d) {
    vector <bool> visited(nVertex, false);
    int totalPaths = 0;
    countAllPaths(s, d, adj, visited, totalPaths);
    return totalPaths;
}

int main() {
    int nVertex, nEdge, u, v;
    scanf("%d %d", &nVertex, &nEdge);
    list <int> *adj = new list<int>[nVertex];
    for (int i = 0; i < nEdge; i++) {
        scanf("%d %d", &u, &v);
        adj[u].pb(v);
    }
    int s = 2, d = 3; // source and destination
    int totalPaths = countPaths(nVertex, adj, s, d);
    printf("%d\n", totalPaths);
}

/*******************************
INPUT
 ----
   - first line, n = 4 Vertex, m = 6 Edge
 4 6
0 1
0 2
0 3
2 0
2 1
1 3

OUTPUT
 -----
 3
 ******************************/
