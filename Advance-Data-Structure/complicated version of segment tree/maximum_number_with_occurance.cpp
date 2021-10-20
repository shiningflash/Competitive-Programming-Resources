#include <bits/stdc++.h>
using namespace std;
#define le 100005

pair<int, int> tree[4*le];

pair<int, int> comp(pair<int, int> a, pair<int, int> b) {
    if (a.first > b.first) return a;
    if (b.first > a.first) return b;
    return make_pair(a.first, a.second + b.second);
}

void init(int arr[], int node, int b, int e) {
    if (b == e) tree[node] = make_pair(arr[b], 1);
    else {
        int left = node << 1, right = left | 1, mid = (b+e) >> 1;
        init(arr, left, b, mid);
        init(arr, right, mid+1, e);
        tree[node] = comp(tree[left], tree[right]);
    }
}

pair<int, int> get_max(int node, int b, int e, int i, int j) {
    if (i > j) return make_pair(INT_MIN, 0);
    if (i == b && j == e) return tree[node];
    int left = node << 1, right = left | 1, mid = (b+e) >> 1;
    return comp(get_max(left, b, mid, i, min(mid, j)), get_max(right, mid+1, e, max(mid+1, i), j));
} 

void update(int node, int b, int e, int i, int val) {
    if (b == e) tree[node] = make_pair(val, 1);
    else {
        int left = node << 1, right = left | 1, mid = (b+e) >> 1;
        if (i <= mid) update(left, b, mid, i, val);
        else update(right, mid+1, e, i, val);
        tree[node] = comp(tree[left], tree[right]);
    }
}

int main() {
    int arr[] = {100001, 3, 5, 7, 11, 11};
    init(arr, 1, 0, 5);

    pair<int, int> x = get_max(1, 0, 5, 0, 5);
    cout << x.first << " " << x.second << endl;

    update(1, 0, 5, 0, 5);
    x = get_max(1, 0, 5, 0, 5);
    cout << x.first << " " << x.second << endl;

    update(1, 0, 5, 3, 107);
    x = get_max(1, 0, 5, 0, 5);
    cout << x.first << " " << x.second << endl;
}

/*

OUTPUT
------
100001 1
11 2
107 1

*/
