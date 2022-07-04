"""
Selection Sort

Time Complexity: O(n^2)
"""


def selection_sort(arr):
    for i in range(len(arr)-1):
        min_index = i
        for j in range(i+1, len(arr)):
            if arr[j] < arr[min_index]:
                min_index = j
        # swap a[i] with a[min_index]
        arr[i], arr[min_index] = arr[min_index], arr[i]
    return arr


if __name__ == '__main__':
    arr = [5, 1, 423, 12, -1, -1231, 9, 0]
    print('before: ', arr)
    arr = selection_sort(arr)
    print('after:  ', arr)
