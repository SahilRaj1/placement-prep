""" Binary Search """

"""
Worst case: O(log n)
Can be applied only to sorted arrays 
"""

def binarySearch(arr, val) -> int:
    if arr != sorted(arr):
        arr.sort()
    s = 0
    e = len(arr)-1
    while s <= e:
        mid = (s + e) // 2
        if arr[mid] == val:
            return mid
        elif arr[mid] < val:
            s = mid+1
        else:
            e = mid-1
    return -1

arr1 = [x for x in range(10)]
print(arr1)
print(binarySearch(arr1, 6))
print(binarySearch(arr1, 20))
