/*
   Binary Simulation LightOJ - 1080 
   Amirul Islam, Feb 18, 2019
*/

#include <bits/stdc++.h>
using namespace std;

const int le = 1e6;
int tree[3*le];

void update(int node, int b, int e, int i, int j) {
    if (i > e || j < b) return;
    if (i <= b && j >= e) {
        tree[node]++;
        return;
    }   
    int left = node << 1, right = left | 1, mid = (b+e) >> 1;
    update(left, b, mid, i, j);
    update(right, mid+1, e, i, j);
}

int query(int node, int b, int e, int pos) {
    if (pos > e || pos < b) return 0;
    if (pos == b && pos == e) return tree[node];
    int left = node << 1, right = left | 1, mid = (b+e) >> 1;
    if (pos <= mid) return tree[node] + query(left, b, mid, pos);
    else return tree[node] + query(right, mid+1, e, pos);
}

char invert(char ch) {
    if (ch == '1') return '0';
    else return '1';
}

int main() {
//    freopen("in", "r", stdin);
    int tst, t = 1, n, q, u, v, pos, aa;
    char bns[le], chk;
    scanf("%d\n", &tst);
    while (tst--) {
        printf("Case %d:\n", t++);
        memset(tree, 0, 3*le);
        scanf("%s\n", bns);
        n = strlen(bns);
        scanf("%d", &q);
        while (q--) {
            getchar();
            scanf("%c", &chk);
            if (chk == 'I') {
                scanf("%d %d", &u, &v);
                update(1, 1, n, u, v);
            } else {
                scanf("%d", &pos);
                aa = query(1, 1, n, pos);
                char ans = bns[pos-1];
                if (aa % 2 == 1) ans = invert(ans);
                printf("%c\n", ans);
            }
        }
    }
}
