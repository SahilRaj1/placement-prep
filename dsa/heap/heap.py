""" Binary Heap"""

class BinaryHeap:
    def __init__(self, size):
        self.list = (size+1) * [None]
        self.size = 0
        self.maxSize = size + 1

# Peek element of the heap
def peekOfHeap(root):
    if not root:
        return None
    else:
        return root.list[1]

# Size of Binary Heap
def sizeOfHeap(root):
    if not root:
        return
    else:
        return root.size

# Level Order Traversal
def levelOrder(root):
    if not root:
        return
    else:
        for i in range(1, root.size+1):
            print(root.list[i], end=" ")

def heapifyTreeInsert(root, index, heapType):
    parentIndex = index//2
    if index <= 1:
        return
    if heapType == "Minimum":
        if root.list[index] < root.list[parentIndex]:
            root.list[index], root.list[parentIndex] = root.list[parentIndex], root.list[index]
        heapifyTreeInsert(root, parentIndex, heapType)
    elif heapType == "Maximum":
        if root.list[index] > root.list[parentIndex]:
            root.list[index], root.list[parentIndex] = root.list[parentIndex], root.list[index]
        heapifyTreeInsert(root, parentIndex, heapType)

def insertNode(root, value, heapType):
    if root.size + 1 == root.maxSize:
        print("Heap is full")
        return
    root.list[root.size + 1] = value
    root.size += 1
    heapifyTreeInsert(root, root.size, heapType)

def heapifyTreeExtract(root, index, heapType):
    leftIndex = index * 2
    rightIndex = index * 2 + 1
    swapChild = 0

    if root.size < leftIndex:
        return
    elif root.size == leftIndex:
        if heapType == "Minimum":
            if root.list[index] > root.list[leftIndex]:
                root.list[index], root.list[leftIndex] = root.list[leftIndex], root.list[index]
                return
        elif heapType == "Maximum":
            if root.list[index] < root.list[leftIndex]:
                root.list[index], root.list[leftIndex] = root.list[leftIndex], root.list[index]
                return
    else:
        if heapType == "Minimum":
            if root.list[leftIndex] < root.list[rightIndex]:
                swapChild = leftIndex
            else:
                swapChild = rightIndex
            if root.list[index] > root.list[swapChild]:
                root.list[index], root.list[swapChild] = root.list[swapChild], root.list[index]
        elif heapType == "Maximum":
            if root.list[leftIndex] > root.list[rightIndex]:
                swapChild = leftIndex
            else:
                swapChild = rightIndex
            if root.list[index] < root.list[swapChild]:
                root.list[index], root.list[swapChild] = root.list[swapChild], root.list[index]
    heapifyTreeExtract(root, swapChild, heapType)

def extractNode(root, heapType):
    if root.size == 0:
        return
    else:
        extractedNode = root.list[1]
        root.list[1] = root.list[root.size]
        root.list[root.size] = None
        root.size -= 1
        heapifyTreeExtract(root, 1, heapType)
        return extractedNode
    
def deleteHeap(root):
    root.list = None
    root.size = 0
    
if __name__ == '__main__':
    newHeap = BinaryHeap(5)
    insertNode(newHeap, 4, "Maximum")
    insertNode(newHeap, 2, "Maximum")
    insertNode(newHeap, 3, "Maximum")
    insertNode(newHeap, 5, "Maximum")
    insertNode(newHeap, 1, "Maximum")
    levelOrder(newHeap)
    print()
    extractNode(newHeap, "Maximum")
    levelOrder(newHeap)
    deleteHeap(newHeap)
