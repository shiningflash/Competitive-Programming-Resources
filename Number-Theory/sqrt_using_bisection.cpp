#include <bits/stdc++.h>
using namespace std;

double mysqrt(int n) {
    int cnt(0);
    double lo = 0.0, hi = n, mid;
    while (hi - lo > .0000001) {
        cnt++;
        mid = (lo + hi) / 2.0;
        if (mid * mid > n) hi = mid;
        else lo = mid;
    }
    printf("\nIteration needed: %d times\n", cnt);
    return mid;
}

int main() {
    double sq = sqrt(15);
    printf("default: %.10lf %.10lf\n", sq, sq * sq);
    double mysq = mysqrt(15);
    printf("bisection: %.10lf %.10lf\n", mysq, mysq * mysq);
}
