"""
Bubble Sort

Time Complexity: O(N^2)
"""


def bubble_sort(arr):
    for i in range(len(arr)):
        swapped = False
        for j in range(len(arr)-i-1):
            # swap with next element if it is smaller
            if arr[j+1] < arr[j]:
                arr[j], arr[j+1] = arr[j+1], arr[j]
                swapped = True
        if not swapped:
            break
    return arr


if __name__ == '__main__':
    arr = [5, 1, 423, 12, -1, -1231, 9, 0]
    print('before: ', arr)
    arr = bubble_sort(arr)
    print('after:  ', arr)
