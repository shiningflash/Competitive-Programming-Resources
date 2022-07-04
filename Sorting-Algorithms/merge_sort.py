"""
Merge Sort

Time Complexity: O(n log n)
"""


def combine(arr, LEFT_SUB, RIGHT_SUB):
    i = j = k = 0

    while i < len(LEFT_SUB) and j < len(RIGHT_SUB):
        if LEFT_SUB[i] < RIGHT_SUB[j]:
            arr[k] = LEFT_SUB[i]
            i += 1
        else:
            arr[k] = RIGHT_SUB[j]
            j += 1
        k += 1

    while i < len(LEFT_SUB):
        arr[k] = LEFT_SUB[i]
        i += 1
        k += 1
    while j < len(RIGHT_SUB):
        arr[k] = RIGHT_SUB[j]
        j += 1
        k += 1

    return arr


def merge_sort(arr):
    if len(arr) < 2:
        return

    # devide whole list into 2 halves at point mid
    mid = len(arr) // 2
    LEFT_SUB = arr[:mid]
    RIGHT_SUB = arr[mid:]

    # sort two halves
    merge_sort(LEFT_SUB)
    merge_sort(RIGHT_SUB)

    # combine two halves
    return combine(arr, LEFT_SUB, RIGHT_SUB)


if __name__ == '__main__':
    arr = [5, 1, 423, 12, -1, -1231, 9, 0]
    print('before: ', arr)
    merge_sort(arr)
    print('after:  ', arr)
