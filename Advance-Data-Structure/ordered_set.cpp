/*

+> Ordered set is a policy based data structure in g++ that keeps the unique elements in sorted order.
It performs all the operations as performed by the set data structure in STL in log(n) complexity
and performs two additional operations also in log(n) complexity.

- order_of_key (k) : Number of items strictly smaller than k
- find_by_order(k) : K-th element in a set (counting from zero)

+> For implementing ordered_set and GNU C++ library contains other Policy based data structures we need to include:

include <ext/pb_ds/assoc_container.hpp>
include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

+> The ordered set implementation is:

tree < int ,  null_type ,  less ,  rb_tree_tag ,  tree_order_statistics_node_update >

Here,
- int : It is the type of the data that we want to insert (KEY).It can be integer, float or pair of int etc
- null_type : It is the mapped policy. It is null here to use it as a set
- less : It is the basis for comparison of two functions
- rb_tree_tag : type of tree used. It is generally Red black trees because it takes log(n) time for insertion and deletion
- tree_order_statistics_node__update : It contains various operations for updating the node variants of a tree-based container

Along with the previous operations of the set, it supports two main important operations

** find_by_order(k): It returns to an iterator to the kth element (counting from zero) in the set in O(logn) time. To find the first element k must be zero.
Let us assume we have a set s : {1, 5, 6, 17, 88}, then :
*(s.find_by_order(2)) : 3rd element in the set i.e. 6
*(s.find_by_order(4)) : 5th element in the set i.e. 88

** order_of_key(k) : It returns to the number of items that are strictly smaller than our item k in O(logn) time.
Let us assume we have a set s : {1, 5, 6, 17, 88}, then :
s.order_of_key(6) : Count of elements strictly smaller than 6 is 2.
s.order_of_key(25) : Count of elements strictly smaller than 25 is 4.

** count of elements between l and r can be found by:
o_set.order_of_key(r+1) – o_set.order_of_key(l)

ref: https://www.geeksforgeeks.org/ordered-set-gnu-c-pbds

*/

/*

two fundamental operations

INSERT(S,x): if x is not in S, insert x into S
DELETE(S,x): if x is in S, delete x from S

and the two type of queries

K-TH(S) : return the k-th smallest element of S
COUNT(S,x): return the number of elements of S smaller than x

*/

#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

int main() {
    //freopen("in", "r", stdin);
    int t, n;
    char ch;
    ordered_set s;
    for (cin >> t; t--; ) {
        cin >> ch >> n;
        if (ch == 'I') s.insert(n);
        else if (ch == 'D') s.erase(n);
        else if (ch == 'C') cout << s.order_of_key(n) << "\n";
        else if (ch == 'K') {
            if (n > s.size()) cout << "invalid\n";
            else cout << *s.find_by_order(n-1) << "\n";
        }
    }
    return 0;
}

/*
Input:
8
I -1
I -1
I 2
C 0
K 2
D -1
K 1
K 2

Output:
1
2
2
invalid

ref: https://www.spoj.com/problems/ORDERSET
*/
