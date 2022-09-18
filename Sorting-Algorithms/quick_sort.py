"""
Quick Sort

Time Complexity
Best Case: O(n log n)
Average Case: O(n log n)
Worst Case: O(n^2)
"""


def quick_sort(arr):
    if len(arr) < 2:
        return arr

    pivot = arr.pop()

    lower_part = []
    greater_part = []

    for x in arr:
        if x < pivot
            lower_part.append(x)
        else:
            greater_part.append(x)

    return quick_sort(lower_part) + [pivot] + quick_sort(greater_part)


if __name__ == '__main__':
    arr = [5, 1, 423, 12, -1, -1231, 9, 0]
    arr = quick_sort(arr)
    print(arr)
