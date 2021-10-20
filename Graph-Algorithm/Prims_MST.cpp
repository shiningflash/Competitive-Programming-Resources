/*
  @topic      - Minimum Spanning Tree (MST)
  @complexity - O(ElogV) - Prim’s algorithm
  @author     - Amirul islam
                   _
   _|_ o._ o._  __|_| _. _|_
  _>| ||| ||| |(_|| |(_|_>| |
                _|
*/

#include <bits/stdc++.h>
using namespace std;

const int mx = 1e3;
const int inf = 1 << 30;

vector < pair <int, int> > graph[mx];

int _distance[mx];
bool visited[mx];
int parent[mx];

struct Node {
    int u, w;

    Node(int u, int w) {
        this->u = u;
        this->w = w;
    }

    bool operator < (const Node& N) const {
        return w > N.w;
    }
};

void prims_MST(int source, int nodes) {
    for (int i = 0; i < nodes; i++) {
        _distance[i] = inf;
        parent[i] = -1;
    }

    visited[source] = true;
    _distance[source] = 0;

    priority_queue <Node> q;
    q.push(Node(source, 0));

    while (!q.empty()) {
        int u = q.top().u;
        q.pop();
        visited[u] = true;

        for (int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i].first;
            int w = graph[u][i].second;

            if (!visited[v] && _distance[v] > w) {
                _distance[v] = w;
                q.push(Node(v, _distance[v]));
                parent[v] = u;
            }
        }
    }
}

void print_MST(int source, int nodes) {
    for (int i = 0; i < nodes; i++) {
        if (i != source) {
            cout << "( " << parent[i] << " - " << i << 
                " ) = " << _distance[i] << "\n";
        }
    }
}

int main() {
    // freopen("in", "r", stdin);

    int nodes, edges, u, v, w;
    cin >> nodes >> edges;
    while (edges--) {
        cin >> u >> v >> w;
        graph[u].push_back(make_pair(v, w));
    }

    int source = 0;
    prims_MST(source, nodes);
    
    print_MST(source, nodes);

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
( 0 - 1 ) = 2
( 3 - 2 ) = 2
( 0 - 3 ) = 1
 */
