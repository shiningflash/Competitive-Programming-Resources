/*
  @topic      - Strongly Connected Component (SCC)
  @complexity - O(V+E)  -  Kosaraju’s algorithm
  @author     - Amirul islam
                   _
   _|_ o._ o._  __|_| _. _|_
  _>| ||| ||| |(_|| |(_|_>| |
                _|
*/

#include <bits/stdc++.h>
using namespace std;

const int mx = 1e3;

vector <int> graph[mx], revgraph[mx];

bool vis[mx];
stack <int> st;

void dfs1(int u) {
    vis[u] = 1;

    for (int i = 0; i < revgraph[u].size(); i++) {
        int v = revgraph[u][i];

        if (vis[v] == 0) {
            dfs1(v);
        }
    }

    st.push(u);
}

void dfs2(int u) {
    vis[u] = 1;
    cout << u << " ";

    for (int i = 0; i < graph[u].size(); i++) {
        int v = graph[u][i];

        if (vis[v] == 0) {
            dfs2(v);
        }
    }
}

int main() {
    int n, u, v;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        revgraph[v].push_back(u);
    }

    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < n; i++) {
        if (vis[i] == 0) {
            dfs1(i);
        }
    }

    memset(vis, 0, sizeof(vis));
    while (!st.empty()) {
        int u = st.top();
        st.pop();

        if (vis[u] == 0) {
            dfs2(u);
            cout << "\n";
        }
    }
    return 0;
}

/*
Input:
-
5
1 0
0 2
2 1
0 3
3 4

Output:
-
4 
3 
0 2 1
*/
