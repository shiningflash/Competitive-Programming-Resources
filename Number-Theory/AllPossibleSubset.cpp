/*
    @algorithm  : all possible subset
    @author     : Amirul Islam
    @complexity : O(N * 2^N)
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

const int mx = 1000000000;

void possibleSubset(int N) {
    for (int i = 0; i < (1 << N); i++) {
        for (int j = 0; j < N; j++) {
            if (i & (1 << j)) {
                cout << j << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    possibleSubset(3);
}

/*
Input:
3

Output:

0 
1 
0 1 
2 
0 2 
1 2 
0 1 2 
*/
