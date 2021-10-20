
// kadane algorithm :: TC - O(N)
// @author :: Amirul Islam 

#include <bits/stdc++.h>
using namespace std;

int maxSubArrSum(int a[], int sz) {
    int cur_max = a[0], global_max = a[0];
    for (int i = 1; i < sz; i++) {
        cur_max = max(a[i], cur_max + a[i]);
        global_max = max(global_max, cur_max);
    }
    return global_max;
}

int maxSubArrSum_withStartEnd(int a[], int sz) {
    int cur_max = 0, global_max = INT_MIN, start(0), end(0), s(0);
    for (int i = 0; i < sz; i++) {
        cur_max = cur_max + a[i];
        if (global_max < cur_max) global_max = cur_max, start = s, end = i;
        if (cur_max < 0) cur_max = 0, s = i + 1;
    }
    printf("\nMax Sub Array Sum = %d\nStart = %d\tEnd = %d\n", global_max, start, end);
}

int main() {
    int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int max_sum = maxSubArrSum(a, sizeof(a)/sizeof(a[0]));
    printf("Max Sub Array Sum = %d", max_sum);
    maxSubArrSum_withStartEnd(a, sizeof(a)/sizeof(a[0]));
}
