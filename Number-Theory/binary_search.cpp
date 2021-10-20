/*
    1. Binary Search
    2. Search Lower Bound
    
    pre-requisite: array must have to be sorted
    if not, then sort it first

    Complexity: unsorted array - O(n log n), sorted - O(log n)
*/

#include <bits/stdc++.h>
using namespace std;

int binary_search(int arr[], int size, int key) {
    int lo = 0, hi = size - 1, mid;
    while (lo <= hi) {
        mid = (lo + hi) >> 1;
        if (key == arr[mid]) return mid;
        if (key > arr[mid]) lo = mid + 1;
        else hi = mid - 1;
    }
    return -1;
}

int searchLowerBound(int arr[], int size, int key) {
    int lo = 0, hi = size - 1, mid, indx = -1;
    while (lo <= hi) {
        mid = (lo + hi) >> 1;
        if (key == arr[mid]) indx = mid, hi = mid - 1;
        else if (key > arr[mid]) lo = mid + 1;
        else hi = mid - 1;
    }
    return lo;
}

int main() {
    int arr[] = {2, 10, 20, 50, 100, 100, 100, 150, 200, 500, 1000};
    int size = *(&arr + 1) - arr;

    sort(arr, arr + size);
    
    // Binary Search
    int key = 10;
    int indx = binary_search(arr, size, key);
    if (indx == -1) printf("%d not found!\n", key);
    else printf("%d found in %d'th position\n", key, indx);

    // Search Lower Bound
    int x = 10;
    int lowbound = searchLowerBound(arr, size, key);
    printf("Lower Bound of %d is %d\n", x, lowbound);
    return 0;
}
