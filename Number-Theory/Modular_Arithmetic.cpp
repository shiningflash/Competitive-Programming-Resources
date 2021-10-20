/*
      @algorithm   : Modular Arithmetic
      @author      : Amirul Islam
      @problem     : 100! % 97
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

const int mx = 1e5+4;

/*
    two formula
    -----------
    1. (a + b) % m = ( (a % m) + (b % m) ) % m
    2. (a * b) % m = ( (a % m) * (b % m) ) % m 

	Note:
	* if N is negetive, you have to make it positive
	* one way can be - adding any mutiple of M with N
	* e.g. -17 % 5 = (-17 + 100) % 5 = 83 % 5 = 3
    
*/

int main() {
    //freopen("in", "r", stdin);

    int n = 100, m = 97;
    int fact = 1;

    for (int i = 1; i <= n; i++) {
        fact = ( (fact % m) * (i % m) ) % m;
    }
    printf("%d\n", fact); // fact = 0
    return 0;
}
