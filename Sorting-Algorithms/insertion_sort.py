"""
Insertion Sort

Time Complexity
Best case: O(N)
Avg. case: O(N^2)
Worst case: O(N^2)

Space Complexity: O(1)
Stable: Yes
"""


def insertion_sort(arr):
    for i in range(len(arr)):
        for j in range(i, 0, -1):
            if arr[j] < arr[j-1]:
                arr[j-1], arr[j] = arr[j], arr[j-1]
            else:
                break
    return arr


if __name__ == '__main__':
    arr = [5, 1, 423, 12, -1, -1231, 9, 0, -1]
    print('before: ', arr)
    insertion_sort(arr)
    print('after:  ', arr)
