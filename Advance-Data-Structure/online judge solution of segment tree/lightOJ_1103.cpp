/*
   Castle Walls LightOJ - 1103
   Amirul Islam, Feb 19, 2019
*/

#include <bits/stdc++.h>
using namespace std;

const int le = 5e6;
const int mx = 1e6;

struct edge {
    int a, b, c;
    bool operator < (const edge &p) const {
        return a < p.a;
    }
};

int tree[le];

int query(int node, int b, int e, int i, int j) {
    if (i > e || j < b || i > j) return 0;
    if (i <= b && j >= e) return tree[node];
    int left = node << 1, right = left | 1, mid = (b+e) >> 1;
    return query(left, b, mid, i, j) + query(right, mid+1, e, i, j);
}

void update(int node, int b, int e, int pos) {
    if (pos > e || pos < b) return;
    if (b == e) {
        tree[node]++;
        return;
    }
    int left = node << 1, right = left | 1, mid = (b+e) >> 1;
    update(left, b, mid, pos);
    update(right, mid+1, e, pos);
    tree[node] = tree[left] + tree[right];
}

int main() {
    int tst, t = 1, p, q, n, m, u, v, cnt;
    for (scanf("%d", &tst); tst--; ) {
        scanf("%d %d", &n, &m);
        vector <edge> vec;
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &p, &q);
            vec.push_back({p, q, 1});
        }
        for (int i = n; i < n+m; i++) {
            scanf("%d %d", &p, &q);
            vec.push_back({p, q, 2});
        }
        
        sort(vec.begin(), vec.end());
        long long int ans = 0;
        
        memset(tree, 0, sizeof(tree));
        for (int i = 0; i < vec.size(); i++) {
            if (vec[i].c == 1) ans += query(1, 1, mx, vec[i].b, mx);
            else update(1, 1, mx, vec[i].b);
        }
        memset(tree, 0, sizeof(tree));
        for (int i = vec.size()-1; i >= 0; i--) {
            if (vec[i].c == 1) ans += query(1, 1, mx, 1, vec[i].b);
            else update(1, 1, mx, vec[i].b);
        }
        printf("Case %d: %lld\n", t++, ans);
    } 
}
