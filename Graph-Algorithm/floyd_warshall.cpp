// time complexity - O(N^3)
// space complexity - O(N^2)

#include <bits/stdc++.h>
using namespace std;
#define inf INT_MAX

int nodes, edges, dis[100][100], u, v, w;

void floyd_warshall() {
    for (int k = 1; k <= nodes; k++) {
        dis[k][k] = 0;
        for (int i = 1; i <= nodes; i++) {
            for (int j = 1; j <= nodes; j++) {
                if (dis[i][k] != inf && dis[k][j] != inf && dis[i][k] + dis[k][j] < dis[i][j]) {
                    dis[i][j] = dis[i][k] + dis[k][j];
                }
            }
        }
    }
}

void print_distance_matrix() {
    for (int i = 1; i <= nodes; i++) {
        for (int j = 1; j <= nodes; j++) {
            if (dis[i][j] == inf) printf("inf ");
            else printf("%d ", dis[i][j]);
        }
        printf("\n");
    }
}

int main() {
    //freopen("in", "r", stdin);
    scanf("%d %d", &nodes, &edges);
    for (int i = 1; i <= nodes; i++) {
        for (int j = 1; j <= nodes; j++) {
            dis[i][j] = inf;
        }
    }
    while (edges--) {
        scanf("%d %d %d", &u, &v, &w);
        dis[u][v] = w;
    }
    floyd_warshall();
    print_distance_matrix();
}

/*
Input:
4 6
4 1 20
1 2 3
2 1 2
2 3 2
3 2 5
4 3 8

Output:
0 3 5 inf 
2 0 2 inf 
7 5 0 inf 
15 13 8 0
*/
