/*
  @topic      - Minimum Spanning Tree (MST)
  @complexity - O(ElogE) - Kruskal's algorithm
  @author     - Amirul islam
                   _
   _|_ o._ o._  __|_| _. _|_
  _>| ||| ||| |(_|| |(_|_>| |
                _|
*/

#include <bits/stdc++.h>
using namespace std;

const int mx = 1e3;

struct Edge {
    int u, v, w;

    Edge(int u, int v, int w) {
        this->u = u;
        this->v = v;
        this->w = w;
    }

    bool operator < (const Edge& e) const {
        return w < e.w;
    }
};

vector <Edge> graph;

int parent[mx];

int find(int r) {
    return (parent[r] == r) ? r : parent[r] = find(parent[r]);
}

void kruskal_MST(int nodes, int edges) {
    sort(graph.begin(), graph.end());

    for (int i = 0; i < nodes; i++) {
        parent[i] = i;
    }

    int cnt = 0, total_cost = 0;

    for (int i = 0; i < edges; i++) {
        int u = find(graph[i].u);
        int v = find(graph[i].v);

        if (u != v) {
            cout << "( " << graph[i].u << " : " << graph[i].v <<
                " ) = " << graph[i].w << "\n";
            
            parent[v] = u;
            total_cost += graph[i].w;

            cnt++;
            if (cnt == nodes - 1) break;
        }
    }
    cout << "\nminimum cost = " << total_cost << "\n";
}

int main() {
    freopen("in", "r", stdin);

    int nodes, edges, u, v, w;
    cin >> nodes >> edges;

    for (int i = 0; i < edges; i++) {
        cin >> u >> v >> w;
        graph.push_back(Edge(u, v, w));
    }

    kruskal_MST(nodes, edges);

    return 0;
}

/*
 stdin
 - 
4 5
0 1 2
0 2 3
0 3 1
2 1 2
3 2 2
 
 stdout
 -
( 0 : 3 ) = 1
( 0 : 1 ) = 2
( 2 : 1 ) = 2

minimum cost = 5
 */
