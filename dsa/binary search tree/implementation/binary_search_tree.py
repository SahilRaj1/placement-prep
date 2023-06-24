""" Binary Search Tree """

class BSTNode:
    def __init__(self, data):
        self.data = data
        self.leftChild = None
        self.rightChild = None

# Inserting in BST
def insertBST(rootNode, nodeValue):
    if rootNode.data is None:
        rootNode.data = nodeValue
    elif nodeValue <= rootNode.data:
        if rootNode.leftChild is None:
            rootNode.leftChild = BSTNode(nodeValue)
        else:
            insertBST(rootNode.leftChild, nodeValue)
    else:
        if rootNode.rightChild is None:
            rootNode.rightChild = BSTNode(nodeValue)
        else:
            insertBST(rootNode.rightChild, nodeValue)
    return

# Traversing in BST
def preOrder(rootNode):
    if rootNode:
        print(rootNode.data)
        preOrder(rootNode.leftChild)
        preOrder(rootNode.rightChild)

def inOrder(rootNode):
    if rootNode:
        inOrder(rootNode.leftChild)
        print(rootNode.data)
        inOrder(rootNode.rightChild)

def postOrder(rootNode):
    if rootNode:
        postOrder(rootNode.leftChild)
        postOrder(rootNode.rightChild)
        print(rootNode.data)

# Searching in BST
def searchBST(rootNode, nodeValue):
    if rootNode.data == nodeValue:
        return True
    elif nodeValue < rootNode.data:
        if rootNode.leftChild:
            return searchBST(rootNode.leftChild, nodeValue)
        else:
            return False
    else:
        if rootNode.rightChild:
            return searchBST(rootNode.rightChild, nodeValue)
        else:
            return False

# Deleting a node in BST
def minValue(rootNode):
    current = rootNode
    while current.leftChild is not None:
        current = current.leftChild
    return current

def deleteNode(rootNode, nodeValue):
    if rootNode is None:
        return rootNode
    if nodeValue < rootNode.data:
        rootNode.leftChild = deleteNode(rootNode.leftChild, nodeValue)
    elif nodeValue > rootNode.data:
        rootNode.rightChild = deleteNode(rootNode.rightChild, nodeValue)
    else:
        if rootNode.leftChild is None:
            temp = rootNode.rightChild
            rootNode = None
            return temp
        if rootNode.rightChild is None:
            temp = rootNode.leftChild
            rootNode = None
            return temp
        
        temp = minValue(rootNode.rightChild)
        rootNode.data = temp.data
        rootNode.rightChild = deleteNode(rootNode.rightChild, temp.data)
    return rootNode

# Deleting entire BST
def deleteBST(rootNode):
    rootNode.data = None
    rootNode.leftChild = None
    rootNode.rightChild = None
    return
