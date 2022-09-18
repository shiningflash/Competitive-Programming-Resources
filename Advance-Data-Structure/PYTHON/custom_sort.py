arr = [[100, 200], [200, 1300], [1000, 1250], [20, 1300]]


# import functools


# def compare(x, y):
#     if x[1] < y[1]:
#         return -1
#     if x[1] == y[1]:
#         if x[0] < y[0]:
#             return -1
#     return 1


# arr = sorted(arr, key=functools.cmp_to_key(compare))

# print(arr)


import functools

def compare(x, y):
    if y[1] > x[1]:
        return 1
    return -1

arr = sorted(arr, key=functools.cmp_to_key(compare))
print(arr)