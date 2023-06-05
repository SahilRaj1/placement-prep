""" Binary Tree"""

from queue import Queue

class TreeNode:
    def __init__(self, data):
        self.data = data
        self.leftChild = None
        self.rightChild = None

# Pre Order Traversal
def preOrderTraversal(rootNode):
    if rootNode:
        print(rootNode.data)
        preOrderTraversal(rootNode.leftChild)
        preOrderTraversal(rootNode.rightChild)

# In Order Traversal
def inOrderTraversal(rootNode):
    if rootNode:
        inOrderTraversal(rootNode.leftChild)
        print(rootNode.data)
        inOrderTraversal(rootNode.rightChild)

# Post Order Traversal
def postOrderTraversal(rootNode):
    if rootNode:
        postOrderTraversal(rootNode.leftChild)
        postOrderTraversal(rootNode.rightChild)
        print(rootNode.data)

# Level Order Traversal
def levelOrderTraversal(rootNode):
    if rootNode:
        q = Queue()
        q.enqueue(rootNode)
        while not(q.isEmpty()):
            root = q.dequeue()
            print(root.data)
            if root.leftChild:
                q.enqueue(root.leftChild)
            if root.rightChild:
                q.enqueue(root.rightChild)

# Searching in Binary Tree
def searchBT(rootNode, value):
    if rootNode:
        q = Queue()
        q.enqueue(rootNode)
        while not(q.isEmpty()):
            root = q.dequeue()
            if root.data == value:
                return True
            if root.leftChild:
                q.enqueue(root.leftChild)
            if root.rightChild:
                q.enqueue(root.rightChild)
    return False

# Inserting a node in Binary Tree
def insert(rootNode, newNode):
    if not rootNode:
        rootNode = newNode
    else:
        q = Queue()
        q.enqueue(rootNode)
        while not(q.isEmpty()):
            root = q.dequeue()
            if root.leftChild:
                q.enqueue(root.leftChild)
            else:
                root.leftChild = newNode
                return
            if root.rightChild:
                q.enqueue(root.rightChild)
            else:
                root.rightChild = newNode
                return

# Deleting a node from Binary Tree
def getDeepestNode(rootNode):
    """:return Deepest Node in the Binary Tree"""
    if rootNode:
        q = Queue()
        q.enqueue(rootNode)
        while not(q.isEmpty()):
            root = q.dequeue()
            if root.leftChild:
                q.enqueue(root.leftChild)
            if root.rightChild:
                q.enqueue(root.rightChild)
        deepestNode = root
        return deepestNode

def deleteDeepestNode(rootNode):
    if rootNode:
        q = Queue()
        q.enqueue(rootNode)
        dNode = getDeepestNode(rootNode)
        while not(q.isEmpty()):
            root = q.dequeue()
            if root == dNode:
                root.data = None
                return
            if root.leftChild:
                if root.leftChild == dNode:
                    root.leftChild = None
                    return
                else:
                    q.enqueue(root.leftChild)
            if root.rightChild:
                if root.rightChild == dNode:
                    root.rightChild = None
                    return
                else:
                    q.enqueue(root.rightChild)

def deleteNode(rootNode, value):
    if rootNode:
        q = Queue()
        q.enqueue(rootNode)
        while not(q.isEmpty()):
            root = q.dequeue()
            if root.data == value:
                dNode = getDeepestNode(rootNode)
                root.data = dNode.data
                deleteDeepestNode(rootNode)
                return
            if root.leftChild:
                q.enqueue(root.leftChild)
            if root.rightChild:
                q.enqueue(root.rightChild)
        print("The value does not exist in the Binary Tree")

# Deleting entire Binary Tree
def deleteBT(rootNode):
    rootNode.data = None
    rootNode.leftChild = None
    rootNode.rightChild = None


newBT = TreeNode("Drinks")
leftChild = TreeNode("Hot")
rightChild = TreeNode("Cold")
newBT.leftChild = leftChild
newBT.rightChild = rightChild

# Pre Order Traversal
# print("\nPre Order Traversal:")
# preOrderTraversal(newBT)

# In Order Traversal
# print("\nIn Order Traversal:")
# inOrderTraversal(newBT)

# Post Order Traversal
# print("\nPost Order Traversal:")
# postOrderTraversal(newBT)

# Level Order Traversal
# print("\nLevel Order Traversal:")
# levelOrderTraversal(newBT)

# Searching
# print("\nSearching in Binary Tree")
# print(searchBT(newBT, "Hot"))

# Inserting node in Binary Tree
tea = TreeNode("Tea")
insert(newBT,tea)
coffee = TreeNode("Coffee")
insert(newBT,coffee)
levelOrderTraversal(newBT)
print()

# Deleting deepest Node in Binary Tree
# deleteDeepestNode(newBT)
# deleteDeepestNode(newBT)
# deleteDeepestNode(newBT)
# deleteDeepestNode(newBT)
# levelOrderTraversal(newBT)

# Deleting a node in Binary Tree
deleteNode(newBT,"Cold")
levelOrderTraversal(newBT)

deleteBT(newBT)
