""" Linear Search """

"""
Worst case: O(n)
"""

def linearSearch(arr, val) -> int:
    for i in range(len(arr)):
        if arr[i] == val:
            return i
    return -1

arr1 = [x for x in range(10)]
print(arr1)
print(linearSearch(arr1, 5))
print(linearSearch(arr1, 20))
