/*
  implementation of BFS
  @author Amirul islam
                   _
   _|_ o._ o._  __|_| _. _|_
  _>| ||| ||| |(_|| |(_|_>| |
                _|
*/

#include <bits/stdc++.h>
using namespace std;

const int mx = 1e5;

bool vis[mx];
vector <int> graph[mx];

void bfs(int u) {
    queue <int> q;
    q.push(u);
    vis[u] = true;

    while (!q.empty()) {
        u = q.front();
        q.pop();
        cout << u << " ";
        for (int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i];
            if (!vis[v]) {
                q.push(v);
                vis[v] = true;
            }
        }
    }
}

int main() {
    freopen("in", "r", stdin);

    int node, edge, u, v;
    cin >> node >> edge;
    while (edge--) {
        cin >> u >> v;
        graph[u].push_back(v);
    }
    for (int i = 0; i < node; i++) {
        if (!vis[i]) {
            bfs(i);
        }
    }
    cout << "\n";
    return 0;
}

/*
Input:
8 10
0 1
0 2
0 3
0 4
1 5
2 5
3 6
4 6
5 7
6 7

Output:
0 1 2 3 4 5 6 7
*/
