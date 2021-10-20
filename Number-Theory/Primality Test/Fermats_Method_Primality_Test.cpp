/*
	@author     : Amirul Islam (shiningflash)
	@complexity : O (k * log(n))
	@algorithm  : Primality Test (Fermat's Method) 
*/

#include <bits/stdc++.h>
using namespace std;

// complexity - O (log(n))
int Fermat_Little_Theorem(int a, int n, int p) {
    int res = 1;
    a = a % p; // update if a >= p
    while (n > 0) {
        if (n & 1) res = (res * a) % p;
        n = n >> 1;
        a = (a * a) % p;
    }
    return res;
}

bool isPrime(int n, int k) {
    // corner cases
	if (n < 2 || n == 4) return false;
	if (n == 2 || n == 3) return true;
	
    // try k times
    while (k > 0) {
        // pick a number in [2 .... n-2]
        int a = 2 + rand() % (n-4);
        if (__gcd(n, a) != 1) return false;
        if (Fermat_Little_Theorem(a, n-1, n) != 1) return false;
        k--;
    }
	return true;
} 

int main() {
	int n = 17, k = 3;
	cout << (isPrime(n, k) ? "Prime" : "Not-prime") << endl;
}