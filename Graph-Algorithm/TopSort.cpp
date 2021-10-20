/*
 * Topological Sort (bfs approach)
 * @author Amirul Islam (shiningfalsh)
                   _
   _|_ o._ o._  __|_| _. _|_
  _>| ||| ||| |(_|| |(_|_>| |
                _|
*/

#include <bits/stdc++.h>
using namespace std;

const int mx = 1e3;

int vis[mx];
vector <int> graph[mx];

void bfs(int node) {
    queue <int> q;

    for (int i = 1; i <= node; i++) {
        if (vis[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << " ";

        for (int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i];
            vis[v]--;

            if (vis[v] == 0) {
                q.push(v);
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
        vis[v]++;
    }

    bfs(node);
    
    cout << "\n";
    return 0;
}

/*
Input:
-----
5 4
1 2
2 3
1 3
1 5

Output:
------
1 4 2 5 3
*/
