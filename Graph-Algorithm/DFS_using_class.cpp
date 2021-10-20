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
#define MX 1e18

#define scanint(a) scanf("%d", &a)
#define scanLLD(a) scanf("%lld", &a)

typedef long long ll;
using namespace std;

/* -------------------------- */

class Graph {
    int numberOfNodes;
    list<int> *adj;
public:
    Graph(int numberOfNodes);
    void addEdge(int u, int v);
    void DFS(int numberOfNodes);
    void dfsVISIT(int numberOfNodes, bool visited[]);
};

Graph::Graph(int numberOfNodes) {
    this->numberOfNodes = numberOfNodes;
    adj = new list<int>[numberOfNodes];
}

void Graph::addEdge(int u, int v) {
    adj[u].pb(v);
}

void Graph::dfsVISIT(int s, bool visited[]) {
    visited[s] = true;
    cout << s << " ";

    list<int>:: iterator i;
    for (i = adj[s].begin(); i != adj[s].end(); i++) {
        if (!visited[*i]) dfsVISIT(*i, visited);
    }
}

void Graph::DFS(int s) {
    bool *visited = new bool[numberOfNodes];
    for (int i = 0; i < numberOfNodes; i++)
        visited[i] = false;
    dfsVISIT(s, visited);
}

int main() {
    int numberOfNodes = 4;
    Graph g(numberOfNodes);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    g.DFS(2);
}

// DFS = 2 0 1 3
