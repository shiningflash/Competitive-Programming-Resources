/************************************************
 * Count number of trees in a forest
 * ---------------------------------
 * 1. Apply DFS on every node.
 * 2. Increment count by one
 * 3. Again perform DFS traversal if some nodes yet not visited.
 * 4. Count will give the number of trees in forest.
 * ----------------------------------------------
 * let, vertex = 5, edge = 3 (0 - 1, 0 - 2, 3 - 4)
 * tree will be (1 - 0 - 2), (3 - 4), so total 2.
 *************************************************/

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

void DFS_again(int u, vector <int> adj[], vector <bool> &visited) {
    visited[u] = true;
    for (int v = 0; v < adj[u].size(); v++)
        if (!visited[adj[u][v]])
            DFS_again(adj[u][v], adj, visited);
}

int count_TREE(vector <int> adj[], int nVertex) {
    vector <bool> visited(nVertex, false);
    int cnt = 0;
    for (int u = 0; u < nVertex; u++) { // DFS
        if (!visited[u]) {
            DFS_again(u, adj, visited);
            cnt++;
        }
    }
    return cnt;
}

int main() {
    int nVertex, nEdge, u, v;
    scanf("%d %d", &nVertex, &nEdge);
    vector <int> adj[nVertex];
    for (int i = 0; i < nEdge; i++) {
        scanf("%d %d", &u, &v);
        adj[u].pb(v);
        adj[v].pb(u);
    }
    cout << count_TREE(adj, nVertex) << "\n";
    return 0;
}

/*******************************
INPUT
 ----
   - first line, n = 5 Vertex, m = 3 Edge
 5 3
0 1
0 2
3 4

OUTPUT
 -----
 2
 ******************************/
