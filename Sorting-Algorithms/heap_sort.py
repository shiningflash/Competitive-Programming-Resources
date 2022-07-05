"""
Heap Sort

Time complexity: O(n log n)
"""


def heapify(arr, length, pos):
    # Find largest node among root and both childrens
    largest = pos
    left = (2 * pos) + 1
    right = (2 * pos) + 2

    if left < length and arr[left] > arr[largest]:
        largest = left
    if right < length and arr[right] > arr[largest]:
        largest = right

    # If largest node is not root, swap largest and heapify
    if largest != pos:
        arr[pos], arr[largest] = arr[largest], arr[pos]
        heapify(arr, length, largest)


def heap_sort(arr):
    length = len(arr)

    # Build max heap
    # we will call heapify function for all parent node
    # number of parent node n // 2
    for i in range(length//2, -1, -1):
        heapify(arr, length, i)

    # Sort process
    # Continue the process from n-1 to 1
    # 1. swap root node and last node
    # 2. skip / remove last node every time
    # 3. heapify current tree
    for i in range(length-1, 0, -1):
        arr[0], arr[i] = arr[i], arr[0]
        heapify(arr, i, 0)


if __name__ == '__main__':
    arr = [5, 1, 423, 12, -1, -1231, 9, 0]
    print('before: ', arr)
    heap_sort(arr)
    print('after:  ', arr)
