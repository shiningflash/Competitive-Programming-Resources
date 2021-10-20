/*
    Bellman Ford Algorithms (shortest path)
    checks negative weight cycles
    time complexity - O(V*E)
*/

#include <bits/stdc++.h>
using namespace std;

struct edge {
    int u, v, w;
};

const int mx = 1e4;
const int inf = INT_MAX;

edge g[mx];
int nodes, edges, uu, vv, ww, dis[mx];

bool BellmanFord(int src) {
    for (int i = 1; i <= nodes; i++) dis[i] = inf;
    dis[src] = 0;

    // relax all edges
    for (int i = 1; i <= nodes; i++) {
        for (int j = 1; j <= edges; j++) {
            uu = g[j].u;
            vv = g[j].v;
            ww = g[j].w;
            if (dis[uu] != inf && dis[uu] + ww < dis[vv]) {
                dis[vv] = dis[uu] + ww;
            }
        }
    }

    // check negative-weight cycles
    // return true if exist, false otherwise
    for (int i = 1; i <= edges; i++) {
        uu = g[i].u;
        vv = g[i].v;
        ww = g[i].w;
        if (dis[uu] != inf && dis[uu] + ww < dis[vv]) return true;
    }
    return false;
}

int main() {
    //freopen("in", "r", stdin);
    scanf("%d %d", &nodes, &edges);
    for (int i = 1; i <= edges; i++) {
        scanf("%d %d %d", &uu, &vv, &ww);
        g[i] = {uu, vv, ww};
    }
    int src_node = 1;
    bool cycle = BellmanFord(src_node);

    // print answer
    if (cycle) printf("Negative weight cycle detected.");
    else {
        printf("u - v = w\n-----------\n");
        for (int i = 1; i <= nodes; i++) {
            printf("%d - %d = %d\n", src_node, i, dis[i]);
        }
    }
}

/*
Input1:
5 7
1 4 35
1 2 40
1 5 5
5 3 10
1 3 25
3 2 10
2 4 2

Output1:
u - v = w
-----------
1 - 1 = 0
1 - 2 = 25
1 - 3 = 15
1 - 4 = 27
1 - 5 = 5

Input2:
3 3
1 2 3
2 3 2
3 1 -10

Output:
Negative weight cycle detected.
*/
