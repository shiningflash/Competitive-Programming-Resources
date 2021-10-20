/*
    @algorithm  : flood fill algorithm
    @author     : Amirul Islam
    @complexity : O(N*M)
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

const int mx = 1e3;

char grid[mx][mx];
bool vis[mx][mx];
int row, column, cnt;

int dx[] = {+0, +0, +1, -1, -1, +1, -1, +1};
int dy[] = {-1, +1, +0, +0, +1, +1, -1, -1};

void floodfill(int i, int j, char ch) {
    if (i < 0 || j < 0 || i >= row || j >= column) return; // base case

    if (grid[i][j] == ch && !vis[i][j]) {
        vis[i][j] = true;
        cnt++;

        for (int m = 0; m < 8; m++) {
            int x = i + dx[m];
            int y = j + dy[m];
            floodfill(x, y, ch);
        }
    }
}

int main() {
    // freopen("in.txt", "r", stdin);

    scanf("%d %d", &row, &column);
    getchar();

    // input 2D grid array
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            scanf("%c", &grid[i][j]);
        }
        getchar();
    }

    // traverse 2D array
    // find dotted region
    int regionR = 0, regionG = 0, regionB = 0;
    int pixelR = 0, pixelG = 0, pixelB = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            cnt = 0;
            if (grid[i][j] == 'R' && !vis[i][j]) {
                floodfill(i, j, 'R');
                regionR++;
                pixelR += cnt;
            }
            else if (grid[i][j] == 'G' && !vis[i][j]) {
                floodfill(i, j, 'G');
                regionG++;
                pixelG += cnt;
            }
            else if (grid[i][j] == 'B' && !vis[i][j]) {
                floodfill(i, j, 'B');
                regionB++;
                pixelB += cnt;
            }
        }
    }
    cout << "R - " << regionR << " region - " << pixelR << " pixel\n";
    cout << "G - " << regionG << " region - " << pixelG << " pixel\n";
    cout << "B - " << regionB << " region - " << pixelB << " pixel\n";
}

/*
Input:
-----
5 12
RRGGGGGRBBBB
GRBGGGRGGGRR
BBRBGBRRRBGR
GBBRBGRRGRGR
RRRRRRRRRRRR

Output:
------
R - 1 region - 29 pixel
G - 4 region - 18 pixel
B - 3 region - 13 pixel
*/
