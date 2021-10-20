/********************************************
 * GRAPH REPRESENTATIONS using STL
 * @author Amirul Islam (shiningflash)
 * *
 * The program basically prints adjacency list
 * of an undirected and weighted graph 
 *********************************************/

#include <bits/stdc++.h>
using namespace std;

void printGraph(vector < pair <int, int> > graph[], int numberfVertex) {
    for (int u = 0; u < numberfVertex; u++) {
        cout << "Node " << u << "\n-\n";
        for (auto it = graph[u].begin(); it != graph[u].end(); it++) {
            int v = it->first;
            int w = it->second;
            cout << "( " << u << " - " << v << " ) - " << w << "\n";
        }
        cout << "\n";
    }
}

int main() {
    int numberOfVertex, numberOfEdge, u, v, w;
    cin >> numberOfVertex >> numberOfEdge;
    vector < pair <int, int> > graph[numberOfVertex];
    for (int i = 0; i < numberOfEdge; i++) {
        cin >> u >> v >> w;
        graph[u].push_back(make_pair(v, w));
        graph[v].push_back(make_pair(u, w));
    }
    printGraph(graph, numberOfVertex);
}


/******************
 INPUT
  ---
  - 1st line, here, 5 nVertex, 7 nEdge
  - after then, u - v - weight
5 7
0 1 10
0 4 20
1 2 30
1 3 40
1 4 50
2 3 60
3 4 70

 OUTPUT:
  -----
Node 0
-
( 0 - 1 ) - 10
( 0 - 4 ) - 20

Node 1
-
( 1 - 0 ) - 10
( 1 - 2 ) - 30
( 1 - 3 ) - 40
( 1 - 4 ) - 50

Node 2
-
( 2 - 1 ) - 30
( 2 - 3 ) - 60

Node 3
-
( 3 - 1 ) - 40
( 3 - 2 ) - 60
( 3 - 4 ) - 70

Node 4
-
( 4 - 0 ) - 20
( 4 - 1 ) - 50
( 4 - 3 ) - 70
 *****************/
