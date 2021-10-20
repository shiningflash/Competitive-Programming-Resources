/*
  implementation of BFS on 2D grid
  @author Amirul islam :: Nov 1, 2019
  @modified Amirul islam :: Jan 24, 2021
                   _
   _|_ o._ o._  __|_| _. _|_
  _>| ||| ||| |(_|| |(_|_>| |
                _|
*/

#include <bits/stdc++.h>
using namespace std;

const int mx = 1e3;

char grid[mx][mx];
int vis [mx][mx];
int dis[mx][mx];

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool isInside(int x, int y, int row, int col) {
    return x >= 0 && x < row && y >= 0 && y < col;
}

void bfs(int sx, int sy, int row, int col) {
    vis[sx][sy] = true;
    queue < pair <int, int> > q;
    q.push(make_pair(sx, sy));

    while (!q.empty()) {
        pair <int, int> top = q.front();
        q.pop();

        for (int k = 0; k < 4; k++) {
            int nx = top.first + dx[k];
            int ny = top.second + dy[k];

            if (isInside(nx, ny, row, col) &&
                grid[nx][ny] != '#' && !vis[nx][ny]) {
                    vis[nx][ny] = true;
                    dis[nx][ny] = dis[top.first][top.second] + 1;
                    q.push(make_pair(nx, ny));
                }
        }
    }
}

void printGrid(int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << dis[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    freopen("in", "r", stdin);

    int row, col;
    cin >> row >> col;
    
    swap(row, col);

    for (int i = 0; i < row; i++) {
        cin >> grid[i];
    }

    bfs(0, 0, row, col);

    printGrid(row, col);

    return 0;
}

/*
Input:
3 3
...
#.#
...
Output:
0 1 2 
0 2 0 
4 3 4
 */
