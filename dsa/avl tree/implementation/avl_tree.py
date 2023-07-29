""" AVL Tree"""

class AVLTreeNode:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None
        self.height = 0

def searchAVL(rootNode, value):
    if rootNode.data == value:
        return True
    elif value < rootNode.data:
        if rootNode.left:
            return searchAVL(rootNode.left, value)
        else:
            return False
    elif value > rootNode.data:
        if rootNode.right:
            return searchAVL(rootNode.right, value)
        else:
            return False

# Traversing in AVL Tree
def preOrder(rootNode):
    if rootNode:
        print(rootNode.data)
        preOrder(rootNode.left)
        preOrder(rootNode.right)

def inOrder(rootNode):
    if rootNode:
        inOrder(rootNode.left)
        print(rootNode.data)
        inOrder(rootNode.right)

def postOrder(rootNode):
    if rootNode:
        postOrder(rootNode.left)
        postOrder(rootNode.right)
        print(rootNode.data)

def getHeight(rootNode) -> int:
    """
    :param rootNode: The node whose height is to be calculated
    :return: The height of the given node
    """
    if not rootNode:
        return -1
    else:
        return 1 + max(getHeight(rootNode.left), getHeight(rootNode.right))

def rightRotation(disbalancedNode):
    newRoot = disbalancedNode.left
    disbalancedNode.left = disbalancedNode.left.right
    newRoot.right = disbalancedNode
    disbalancedNode.height = getHeight(disbalancedNode)
    newRoot.height = getHeight(newRoot)
    return newRoot

def leftRotation(disbalancedNode):
    newRoot = disbalancedNode.right
    disbalancedNode.right = disbalancedNode.right.left
    newRoot.left = disbalancedNode
    disbalancedNode.height = getHeight(disbalancedNode)
    newRoot.height = getHeight(newRoot)
    return newRoot

def heightDiff(rootNode):
    if not rootNode:
        return 0
    return getHeight(rootNode.left) - getHeight(rootNode.right)

# Inserting a node in AVL Tree
def insertNode(rootNode, nodeValue):
    if not rootNode:
        return AVLTreeNode(nodeValue)
    elif nodeValue < rootNode.data:
        rootNode.left = insertNode(rootNode.left, nodeValue)
    else:
        rootNode.right = insertNode(rootNode.right, nodeValue)

    rootNode.height = getHeight(rootNode)
    height_diff = heightDiff(rootNode)

    # LL condition
    if height_diff > 1 and nodeValue < rootNode.left.data:
        return rightRotation(rootNode)
    # LR condition
    if height_diff > 1 and nodeValue > rootNode.left.data:
        rootNode.left = leftRotation(rootNode.left)
        return rightRotation(rootNode)
    # RR condition
    if height_diff < -1 and nodeValue > rootNode.right.data:
        return leftRotation(rootNode)
    # RL condition
    if height_diff < -1 and nodeValue < rootNode.right.data:
        rootNode.right = rightRotation(rootNode.right)
        return leftRotation(rootNode)
    return rootNode

def minValue(rootNode):
    if rootNode is None or rootNode.left is None:
        return rootNode
    return minValue(rootNode.left)

# Deleting a Node in AVL Tree
def deleteNode(rootNode, nodeValue):
    if not rootNode:
        return rootNode
    elif nodeValue < rootNode.data:
        rootNode.left = deleteNode(rootNode.left, nodeValue)
    elif nodeValue > rootNode.data:
        rootNode.right = deleteNode(rootNode.right, nodeValue)
    else:
        if rootNode.left is None:
            temp = rootNode.right
            rootNode = None
            return temp
        elif rootNode.right is None:
            temp = rootNode.left
            rootNode = None
            return temp
        temp = minValue(rootNode.right)
        rootNode.data = temp.data
        rootNode.right = deleteNode(rootNode.right, temp.data)

        # Rotation for balancing
        height_diff = heightDiff(rootNode)

        # LL condition
        if height_diff > 1 and heightDiff(rootNode.left) > 0:
            return rightRotation(rootNode)
        # LR condition
        if height_diff > 1 and heightDiff(rootNode.left) < 0:
            rootNode.left = leftRotation(rootNode.left)
            return rightRotation(rootNode)
        # RR condition
        if height_diff < -1 and heightDiff(rootNode.right) < 0:
            return leftRotation(rootNode)
        # RL condition
        if height_diff < -1 and heightDiff(rootNode.left) > 0:
            rootNode.right = rightRotation(rootNode.right)
            return leftRotation(rootNode)

        return rootNode

    # Delete entire AVL Tree
    def deleteAVLTree(rootNode):
        rootNode.data = None
        rootNode.left = None
        rootNode.right = None
