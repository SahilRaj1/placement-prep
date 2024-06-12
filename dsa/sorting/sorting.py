""" Sorting Algorithms """
import math

# Bubble Sort
def bubbleSort(arr):
    """
        Time complexity: O(n^2)
        Space complexity: O(1)
    """
    for i in range(len(arr)-1, 0, -1):
        for j in range(i):
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]

    return arr


# Selection Sort
def selectionSort(arr):
    """
        Time complexity: O(n^2)
        Space complexity: O(1)
    """
    for i in range(len(arr)):
        min_index = i
        for j in range(i+1, len(arr)):
            if arr[j] < arr[min_index]:
                min_index = j
        arr[i], arr[min_index] = arr[min_index], arr[i]

    return arr


# Insertion Sort
def insertionSort(arr):
    """
        Time complexity: O(n^2)
        Space complexity: O(1)
    """
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        while j>=0 and key < arr[j]:
            arr[j+1] = arr[j]
            j -= 1
        arr[j+1] = key

    return arr


# Bucket Sort
def bucketSort(arr):
    """
        Time complexity: O(n*logn)
        Space complexity: O(n)
    """
    numberOfBuckets = round(math.sqrt(len(arr)))
    maxValue = max(arr)
    temp = []
    for i in range(numberOfBuckets):
        temp.append([j for j in arr if math.ceil(j*numberOfBuckets/maxValue)==i+1])
        temp[i].sort()
    
    k = 0
    for i in range(numberOfBuckets):
        for j in range(len(temp[i])):
            arr[k] = temp[i][j]
            k += 1

    return arr


# Merge Sort
def merge(arr, l, m, r):
    n1 = m-l+1
    n2 = r-m
    L = [0] * n1
    R = [0] * n2

    for i in range(n1):
        L[i] = arr[l+i]

    for j in range(n2):
        R[j] = arr[m+1+j]

    i = 0
    j = 0
    k = l
    while i<n1 and j<n2:
        if L[i] <= R[j]:
            arr[k] = L[i]
            i += 1
        else:
            arr[k] = R[j]
            j += 1
        k += 1

    while i<n1:
        arr[k] = L[i]
        i += 1
        k += 1

    while j<n2:
        arr[k] = R[j]
        j += 1
        k += 1

def mergeSort(arr, l, r):
    """
        Time complexity: O(n*logn)
        Space complexity: O(n)
    """
    if l < r:
        m = (l+r-1)//2
        mergeSort(arr, l, m)
        mergeSort(arr, m+1, r)
        merge(arr, l, m, r)

    return arr


# Quick Sort
def partition(arr, low, high):
    i = low - 1
    pivot = arr[high]
    for j in range(low, high):
        if arr[j] <= pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]
    arr[i+1], arr[high] = arr[high], arr[i+1]
    return (i+1)

def quickSort(arr, low, high):
    """
        Time complexity: O(n*logn)
        Space complexity: O(1)
    """
    if low < high:
        pi = partition(arr, low, high)
        quickSort(arr, low, pi-1)
        quickSort(arr, pi+1, high)


# Heap Sort
def heapify(arr, n, i):
    smallest = i
    l = 2*i + 1
    r = 2*i + 2
    if l < n and arr[l] < arr[smallest]:
        smallest = l
    if r < n and arr[r] < arr[smallest]:
        smallest = r

    if smallest != i:
        arr[i], arr[smallest] = arr[smallest], arr[i]
        heapify(arr, n, smallest)

def heapSort(arr):
    """
        Time complexity: O(n*logn)
        Space complexity: O(1)
    """
    n = len(arr)
    for i in range(int(n/2)-1, -1, -1):
        heapify(arr, n, i)

    for i in range(n-1, 0, -1):
        arr[i], arr[0] = arr[0], arr[i]
        heapify(arr, i, 0)
    arr.reverse()

    return arr


if __name__ == '__main__':
    customList = [2, 1, 4, 5, 7, 3, 6, 9, 8]
    # print(bubbleSort(customList))
    # print(selectionSort(customList))
    # print(insertionSort(customList))
    # print(bucketSort(customList))
    # print(mergeSort(customList, 0, 8))
    # quickSort(customList, 0, 8)
    # print(customList)
    # print(heapSort(customList))
