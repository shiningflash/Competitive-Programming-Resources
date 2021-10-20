/*
    @algorithm  : two pointer (GREEDY)
    @complexity : O(N)
    @author     : Amirul Islam
    @problem    : Pair Sum Problem
*/

#include <bits/stdc++.h>
using namespace std;

// XXXXXXXXXXXXXXXXXXXXXXXXXXXX
// ignore this (Naive approach)
// complexity: O(N^2)
bool NaiveApproach(int a[], int n, int key) {
	for (int i = 0; i < n-1; i++) {
		for (int j = i+1; j < n; j++) {
			if (a[i] + a[j] == key) return true;
		}
	}
	return false;
}

// two pointer technique
// complexity: O(N)
bool hasPairSum(int a[], int n, int key) {
	for (int i = 0, j = n-1; i < j; ) {
		if (a[i] + a[j] == key) return true;
		else if (a[i] + a[j] > key) j--;
		else i++;
	}
	return false;
}

int main() {
        //freopen("in", "r", stdin);

	int a[] = {1, 3, 67, 323, 777, 987, 1001};
	int size = sizeof(a) / sizeof(a[0]);
	int key = 68;
	if (hasPairSum(a, size, key)) printf("YES\n");
	else printf("NO\n");
}
