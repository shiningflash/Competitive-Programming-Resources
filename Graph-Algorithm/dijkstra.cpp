/*
  @topic      - Shortest Path Algorithm
  @complexity - O(V*logV+E) - Dijkstra’s algorithm
  @author     - Amirul islam
                   _
   _|_ o._ o._  __|_| _. _|_
  _>| ||| ||| |(_|| |(_|_>| |
                _|
*/

#include <bits/stdc++.h>
using namespace std;

const int inf = 1 << 30;
const int mx = 1e3;

vector < pair <int, int> > graph[mx];

int dis[mx];

struct Node {
    int u, w;

    Node(int u, int w) {
        this->u = u;
        this->w = w;
    }

    bool operator < (const Node& N) const {
        return w < N.w;
    }
};

void dijkstra(int src, int nodes) {
    for (int i = 1; i <= nodes; i++) {
        dis[i] = inf;
    }

    priority_queue <Node> q;
    q.push(Node(src, 0));
    dis[src] = 0;

    while (!q.empty()) {
        Node top = q.top();
        q.pop();
        int u = top.u;

        for (int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i].first;
            int w = graph[u][i].second;

            if (dis[u] + w < dis[v]) {
                dis[v] = dis[u] + w;
                q.push(Node(v, dis[v]));
            }
        }
    }
}

void print_distance(int src, int nodes) {
    printf("u - v = w\n-----------\n");
    for (int i = 1; i <= nodes; i++) {
        printf("%d - %d = %d\n", src, i, dis[i]);
    }
}

int main() {
    // freopen("in", "r", stdin);

    int nodes, edges, u, v, w, src;
    cin >> nodes >> edges;

    while (edges--) {
        cin >> u >> v >> w;
        graph[u].push_back(make_pair(v, w));
        graph[v].push_back(make_pair(u, w));
    }

    cout << "Enter source: ";
    cin >> src;

    dijkstra(src, nodes);

    print_distance(src, nodes);

    return 0;
}

/*
Input:
5 7
1 4 35
1 2 40
1 5 5
5 3 10
1 3 25
3 2 10
2 4 2

1

Output:
u - v = w
---------
1 - 1 = 0
1 - 2 = 25
1 - 3 = 15
1 - 4 = 27
1 - 5 = 5
*/
