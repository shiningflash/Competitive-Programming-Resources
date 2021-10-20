#include <bits/stdc++.h>
using namespace std;
#define mx 1000000

int a[(mx >> 5) + 2];

bool Check(int n, int pos) {
    return (bool) (n & (1 << pos));
}

int Set(int n, int pos) {
    return n = n | (1 << pos);
}

void sieve() {
    int rt = (int) sqrt(mx);
    for (int i = 3; i <= rt; i += 2) {
        if (Check(a[i >> 5], i & 31) == 0) {
            for (int j = i * i, k = i << 1; j <= mx; j += k) {
                a[j >> 5] = Set(a[j >> 5], j & 31);
            }
        }
    }
    printf("2");
    for (int i = 3; i <= mx; i += 2) {
        if (Check(a[i >> 5], i & 31) == 0) printf(" %d", i);
    }
    printf("\n");
}

int main() {  
    sieve();
}
