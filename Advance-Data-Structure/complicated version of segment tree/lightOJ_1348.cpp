// have bugs in this code
// need to resolve
// 11 March, 2019
// Amirul Islam

#include <bits/stdc++.h>
#define le 30005
using namespace std;

vector <int> vec[le];
int arr[le], par[le][20], aa[le<<1], bb[le<<1], cc[le<<1], level[le], tree[le*6];
int tt;

void dfs(int n, int p, int lev = 0) {
    aa[n] = ++tt;
    bb[tt] = n;
    par[n][0] = p;
    level[n] = lev;
    for (int i = 0; i < vec[n].size(); i++) {
        if (vec[n][i] != p) dfs(vec[n][i], n, lev+1);
    }
    cc[n] = ++tt;
    bb[tt] = n;
}

void init(int node, int b, int e) {
    if (b == e) {
        tree[node] = 0;
        int k = bb[b];
        if (aa[k] == b) tree[node] = arr[k];
        else tree[node] = -arr[k];
        return;
    }
    int left = node << 1, right = left | 1, mid = (b+e) >> 1;
    init(left, b, mid);
    init(right, mid+1, e);
    tree[node] = tree[left] + tree[right];
}

void dynamic_p(int n) {
    for (int i = 1; i < 18; i++) {
        for (int j = 1; j <= n; j++) {
            if (par[j][i-1]) par[j][i] = par[par[j][i-1]][i-1];
        }
    }
}

void update(int node, int b, int e, int i, int val) {
    if (b == e) tree[node] = val;
    else {
        int left = node << 1, right = left | 1, mid = (b+e) >> 1;
        if (i <= mid) update(left, b, mid, i, val);
        else update(right, mid+1, e, i, val);
        tree[node] = tree[left] + tree[right];
    }
}

int query(int node, int b, int e, int i, int j) {
    if (i > j) return 0;
    if (i == b && j == e) return tree[node];
    int left = node << 1, right = left | 1, mid = (b+e) >> 1;
    return query(left, b, mid, i, min(mid, j)) + query(right, mid+1, e, max(mid+1, i), j);
}

int lca(int u, int v) {
    if (level[u] < level[v]) swap(u, v);
    for (int i = 17; i >= 0; i--) {
        if (level[u]-(1<<i) >= level[v]) u = par[u][i];
    }
    if (u == v) return u;
    for (int i = 17; i >= 0; i--) {
        if (par[u][i] && par[u][i] != par[v][i]) {
            u = par[u][i];
            v = par[v][i];
        }
    }
    return par[u][0];
}

int main() {
    int t = 1, tst, n, q, u, v, cnt, k, i, j, zz;
    for (scanf("%d", &tst); tst--; ) {
        tt = 0;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            vec[i].clear();
            scanf("%d", &arr[i]);
            for (int j = 0; j < 20; par[i][j] = 0, j++);
        }
        for (int i = 1; i <= n; i++) {
            scanf("%d %d", &u, &v);
            u++; v++;
            vec[u].push_back(v);
            vec[v].push_back(u);
        }
        dfs(1, 1);

        init(1, 1, tt);

        dynamic_p(n);

        scanf("%d", &q);
        printf("case %d:\n", t++);
        while (q--) {
            scanf("%d %d %d", &k, &i, &j);
            ++i;
            if(zz) {
                arr[i] = j;
                update(1, 1, tt, aa[i], j);
                update(1, 1, tt, cc[i], -j);
            }
            else {
                cnt = lca(i, ++j);
                int res = query(1, 1, tt, aa[cnt], aa[i]);
                res = query(1, 1, tt, aa[cnt], aa[j]);
                printf("%d\n", res - arr[cnt]);
            }
        }
    }
    return 0;
}
