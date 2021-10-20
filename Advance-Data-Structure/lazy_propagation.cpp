/**************************************
 * author - Amirul Islam (shiningflash)
 --------------------------------------
 * Segment tree "Lazy Propagation"
 * update a range, get sum of a range
 --------------------------------------
 * height (total) - log(n)
 * per query - O(log n)
 * range update - O(log n)
 * init func - O(n log n)
 * total complexity - O(n log n)
 **************************************/

#include <bits/stdc++.h>
using namespace std;

const int mx = 100005;

/******* param ***********
 * arr[]  - main array
 * tree[] - conceptual tree
 * b      - begin index
 * e      - end index
 * node   - root node index
 * ls     - left part sum
 * rs     - right part sum
 * val    - new value to add
 * prop   - propagate value
 * carry  - carrying propagate value
 *************************/

int arr[mx];

struct info {
	int sum, prop;
} tree[mx * 4];

void init(int node, int b, int e) {
	if (b == e) {
		tree[node].sum = arr[b];
		return;
	}
	int left = node << 1;
	int right = (node << 1) + 1;
	int mid = (b + e) >> 1;
	init(left, b, mid);
	init(right, mid + 1, e);
	tree[node].sum = tree[left].sum + tree[right].sum;
}

int query(int node, int b, int e, int i, int j, int carry = 0) {
	if (i > e || j < b) return 0;
	if (b >= i && e <= j) return tree[node].sum + carry * (e - b + 1);
	int left = node << 1;
	int right = (node << 1) + 1;
	int mid = (b + e) >> 1;
	int ls = query(left, b, mid, i, j, carry + tree[node].prop);
	int rs = query(right, mid + 1, e, i, j, carry + tree[node].prop);
	return ls + rs;
}

void update(int node, int b, int e, int i, int j, int val) {
	if (i > e || j < b) return;
	if (b >= i && e <= j) {
		tree[node].sum += ((e - b + 1) * val);
		tree[node].prop = val;
		return;
	}
	int left = node << 1;
	int right = (node << 1) + 1;
	int mid = (b + e) >> 1;
	update(left, b, mid, i, j, val);
	update(right, mid + 1, e, i, j, val);
	tree[node].sum = tree[left].sum + tree[right].sum + (e - b + 1) * tree[node].prop;
}

int main() {
	// freopen("in", "r", stdin);

	int n, q, k, i, j, val;
	scanf("%d %d", &n, &q);
	for (int i = 1; i <= n; scanf("%d", &arr[i]), i++);
	init(1, 1, n);
	while (q--) {
		scanf("%d %d %d", &k, &i, &j);
		if (k == 0) printf("%d\n", query(1, 1, n, i, j, 0));
		else if (k == 1) {
			scanf("%d", &val);
			update(1, 1, n, i, j, val);
		}
	}
}

/****************
 stdin
 -----
 6 5

 2 2 4 4 2 2

 0 1 6
 1 1 2 2
 0 1 6
 1 5 6 2
 0 1 6

 stdout
 ------
 16
 20
 24
 **************/
