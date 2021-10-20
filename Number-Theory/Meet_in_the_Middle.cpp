/*
    @algorithm  : Meet in the middle
    @complexity : O(n*n*log2(n*n))
    @author     : Amirul Islam
    @problem    : 4 values whose sum is 0 (SPOJ - SUMFOUR)
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

const int mx = 4e4+4;

int main() {
    //freopen("in", "r", stdin);

	int n;
	scanf("%d", &n);

	int a[n], b[n], c[n], d[n];
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d %d", &a[i], &b[i], &c[i], &d[i]);
	}

	int X[n*n], Y[n*n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			X[i*n+j] = a[i] + b[j];
			Y[i*n+j] = c[i] + d[j];
		}
	}

	ll sum = 0;
	sort(Y, Y+n*n);
	for (int i = 0; i < n*n; i++) {
		int lowpos = lower_bound(Y, Y+n*n, -X[i]) - Y;
		if (Y[lowpos] == -X[i]) {
			sum += ((upper_bound(Y, Y+n*n, -X[i])-Y) - lowpos);
		}
	}
        printf("%lld\n", sum);
        return 0;
}
