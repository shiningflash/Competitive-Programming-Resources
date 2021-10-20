/********************************************
 * GRAPH REPRESENTATIONS using unordered_set (or hashing)
 * @author Amirul Islam (shiningflash)
 *
 * Undirected Graph__
 *
 * cons:----
 * This approach cannot be used for graphs containing parallel edges.
 * Edges are not stored in any order.
 *
 * pros:----
 * The edge search operation can be further optimized to O(1)
 * using unordered_set which uses hashing internally.
 *******************************************/

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

void printGraph(int nVertex, unordered_set <int> *adj) {
    for (int i = 0; i < nVertex; i++) {
        unordered_set <int> lst = adj[i];
        printf("%d => ", i);
        for (auto it = lst.begin(); it != lst.end(); it++)
            cout << *it << " ";
        printf("\n");
    }
}

void searchGraph(int nVertex, unordered_set <int> *adj, int src, int dest) {
    auto it  = adj[src].find(dest);
    if (it == adj[src].end()) // not found
        printf("%d to %d: No, Edge not found!\n", src, dest);
    else
        printf("%d to %d: Yes, Edge Found!\n", src, dest);
}

int main() {
    // build graph
    int nVertex, nEdge, u, v;
    scanf("%d %d", &nVertex, &nEdge);
    unordered_set <int> *adj = new unordered_set <int>[nVertex];

    // for undirected graph
    for (int i = 0; i < nEdge; i++) {
        scanf("%d %d", &u, &v);
        adj[u].insert(v);
        adj[v].insert(u);
    }

    // print graph
    printGraph(nVertex, adj);
    printf("\n");

    // search graph
    // @complexity O(1)
    searchGraph(nVertex, adj, 2, 1); // src - 2, dest - 1
    searchGraph(nVertex, adj, 0, 3); // src - 0, dest - 3
}

/******************
 INPUT
  ---
  - here, 5 nVertex, 7 nEdge
5 7
0 1
0 4
1 2
1 3
1 4
2 3
3 4

 OUTPUT:
  -----
0 => 4 1
1 => 4 3 0 2
2 => 3 1
3 => 4 1 2
4 => 3 0 1

2 to 1: Yes, Edge Found!
0 to 3: No, Edge not found!
 *****************/
