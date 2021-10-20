/*
  Diablo LightOJ - 1087 
  Amirul Islam, Feb 18, 2019
*/

#include <bits/stdc++.h>
using namespace std;

const int le = 2e5+9;
int tree[le*4], n, tst, t = 1, q;

void init(int node, int b, int e) {
    if (b == e) {
        if (b <= n && e <= n) {
            tree[node] = 1;
            return;
        } else return;
    }
    int left = node << 1, right = left | 1, mid = (b+e) >> 1;
    init(left, b, mid);
    init(right, mid+1, e);
    tree[node] = tree[left] + tree[right];
    return;
}

void update(int node, int b, int e, int pos, int val) {
    if (b > pos || e < pos) return;
    if (b == e) {
        tree[node] = val;
        return;
    }
    int left = node << 1, right = left | 1, mid = (b+e) >> 1;
    update(left, b, mid, pos, val);
    update(right, mid+1, e, pos, val);
    tree[node] = tree[left] + tree[right];
}

int query(int node, int b, int e, int pos) {
    if (tree[node] < pos) return -1;
    if (b == e) return b;
    int left = node << 1, right = left | 1, mid = (b+e)  >> 1;
    if (pos <= tree[left]) return query(left, b, mid, pos);
    else return query(right, mid+1, e, pos-tree[left]);
}

int main() {
    // freopen("in", "r", stdin);
    scanf("%d", &tst);
	for (int t = 1; t <= tst; t++) {
		memset(tree, 0, sizeof(tree));
		scanf("%d %d", &n, &q);
		int a[n+q+1];
		for (int i = 1; i <= n; scanf("%d", &a[i]), i++);
		init(1, 1, 2*n);
		printf("Case %d:\n", t);
		int x = n, p;
		while (q--) {
			char c[2];
			scanf("%s", c);
			if (c[0] == 'a') {
				scanf("%d", &p);
				a[++x] = p;
				update(1, 1, 2*n, x, 1);
			}
			else {
				scanf("%d", &p);
				int node = query(1, 1, 2*n, p);
				if (node == -1) printf("none\n");
				else {
					printf("%d\n", a[node]);
					update(1, 1, 2*n, node, 0);
				}
			}
		}
	}
	return 0;
}
