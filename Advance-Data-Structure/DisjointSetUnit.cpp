/*
    @data_structure  : Disjoint Set Unit (DSU)
    @implementation  : Kruskal's MST, Tarjan's offline LCA
    @author          : Amirul Islam
*/

#include <bits/stdc++.h>
using namespace std;

const int mx = 1e5+5;
int par[mx];

// return the representation of r
int Find(int r) {
	if (par[r] == r) return r;
	return par[r] = Find(par[r]);
}

// make Union
void Union(int u, int v) {
	par[u] = v;
}

// at the beginning, everyone's representative is it itself
void init(int n) {
	for (int i = 1; i <= n; i++) par[i] = i;
}

int main() {
    //freopen("in", "r", stdin);

	int node, relation, a, b;
	scanf("%d %d", &node, &relation);
	init(node);
	while (relation--) {
		scanf("%d %d", &a, &b);
		int u = Find(a);
		int v = Find(b);
		if (u == v) printf("%d and %d are already friend\n", a, b);
		else Union(u, v);
	}
        return 0;
}

/*
Input:
3 5
1 2
2 3
1 2
3 2
1 3

Output:
1 and 2 are already friend
3 and 2 are already friend
1 and 3 are already friend
*/
