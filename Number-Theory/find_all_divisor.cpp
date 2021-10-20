/*
    @author     : Amirul Islam (shiningflash)
    @topic      : Finding All Divisor
    @complexity : O(sqrt(N))
*/

#include <bits/stdc++.h>
using namespace std;
#define MAX 100000

int fact[MAX];

void factor(int n) {
    int j = 0;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            fact[j++] = i;
            if (i != sqrt(n)) fact[j++] = n / i;
        }
    }
    sort(fact, fact+j);
    for (int i = 0; i < j; i++) cout << fact[i] << " ";
    cout << endl;
}

int main() {
    int n;
    while (cin >> n) factor(n);
}
