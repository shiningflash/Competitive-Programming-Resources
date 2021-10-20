/*
  Ghajini LightOJ -  1093
  Amirul Islam, Feb 18, 2019
*/

#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> dual;
const int mx = 1e5 + 5;
const int inf = 1e9 + 5;


dual tree[4*mx];
int t, tst, n, q, x;

dual merge(dual u, dual v) {
	return {max(u.first, v.first), min(u.second, v.second)};
}

dual query(int node, int b, int e, int i, int j) {
	if (i > e || j < b) return {-inf, inf};
	if (b >= i && e <= j) return tree[node];
	int left = node << 1, right = left | 1, mid = (b + e) >> 1;
	return merge(query(left, b, mid, i, j), query(right, mid+1, e, i, j));
}

void update(int node, int b, int e, int i, int val) {
	if (i > e || i < b) return;
	if (b == e) {
		tree[node].first = tree[node].second = val;
		return;
	}
	int left = node << 1, right = left | 1, mid = (b + e) >> 1;
	update(left, b, mid, i, val);
	update(right, mid+1, e, i, val);
	tree[node] = merge(tree[left], tree[right]);
}

int main() {
//	freopen("in", "r", stdin);
	scanf("%d", &tst);
	for (int t = 1; t <= tst; t++) {
		for (int i = 1; i < 4*mx; i++) tree[i] = {-inf, -inf};
		scanf("%d %d", &n, &q);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &x);
			update(1, 1, n, i, x);
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			dual xx = query(1, 1, n, i, min(i + q - 1, n));
			ans = max(ans, abs(xx.first - xx.second));
		}
		printf("Case %d: %d\n", t, ans);
	}
	return 0;
}
