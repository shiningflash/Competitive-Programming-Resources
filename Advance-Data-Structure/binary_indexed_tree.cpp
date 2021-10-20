// using binary indexed tree
// Fenwick Tree
// complexity - O(n)
// update - O(log n)
// query - O(log n)
 
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll sz = 2e7+7;
ll a[sz], b[sz];
 
void update(ll id, ll n) {
	while (id <= n) {
		b[id] += 1;
		id += (id & -id);
	}
}
 
ll query(ll id) {
	ll sum (0);
	while (id >= 1) {
		 sum += b[id];
		 id -= (id & -id); 
	}
	return sum;
}
 
int main() {
	ll t, n, c;
	for (scanf("%lld", &t); t--; ) {
		scanf("%lld", &n);
		ll mx(0), x(0);
		memset(b, 0, sizeof(b));
		for (ll i = 0; i < n; i++) {
			scanf("%lld", &a[i]);
			mx = max(a[i], mx);
		}
		for (ll i = n-1; i >= 0; i--) {
			if (a[i]) {
				x += query(a[i]);
				update(a[i] + 1, mx);
			}
		}
		printf("%lld\n", x);
		for (ll i = 0; i < n; a[i] = 0, i++);
	}
	return 0;
} 
