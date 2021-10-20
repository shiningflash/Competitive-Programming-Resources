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

void dfsVISIT(list<int> *adj, bool visited[], int s) {
    visited[s] = true;
    printf("%d ", s);

    list <int>:: iterator i;
    for (i = adj[s].begin(); i != adj[s].end(); i++) {
        if (!visited[*i]) dfsVISIT(adj, visited, *i);
    }
}

void DFS(list<int> *adj, int nVertex, int s) {
    printf("DFS: ");
    bool *visited = new bool[nVertex];
    for (int i = 0; i < nVertex; i++)
        visited[i] = false;
    dfsVISIT(adj, visited, s);
    printf("\n");
}

void BFS(list<int> *adj, int nVertex, int s) {
    bool *visited = new bool[nVertex];
    for (int i = 0; i < nVertex; i++)
        visited[i] = false;

    list <int> q;
    visited[s] = true;
    q.pb(s);

    printf("BFS: ");
    list<int>:: iterator i;
    while (!q.empty()) {
        s = q.front();
        printf("%d ", s);
        q.pop_front();
        for (i = adj[s].begin(); i != adj[s].end(); i++) {
            if (!visited[*i]) {
                visited[*i] = true;
                q.pb(*i);
            }
        }
    }
    printf("\n");
}

int main() {
    int nVertex, nEdge, u, v;
    scanf("%d %d", &nVertex, &nEdge);
    list <int> *adj = new list<int>[nVertex];
    for (int i = 0; i < nEdge; i++) {
        scanf("%d %d", &u, &v);
        adj[u].pb(v);
    }
    BFS(adj, nVertex, 2); // source node - 2
    DFS(adj, nVertex, 2); // source node - 2
}


/************
INPUT
 ---
4 6
0 1
0 2
1 2
2 0
2 3
3 3

 OUTPUT
 -----
BFS: 2 0 3 1
DFS: 2 0 1 3
**************/
