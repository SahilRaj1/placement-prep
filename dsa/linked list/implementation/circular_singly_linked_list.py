""" Circular Singly Linked List """

class Node:
    def __init__(self, value=None):
        self.value = value
        self.next = None

class CircularSinglyLinkedList:
    def __init__(self):
        self.head = None
        self.tail = None

    def __iter__(self):
        node = self.head
        while node:
            yield node
            node = node.next
            if node == self.tail.next:
                break

    # Creating a CSLL
    def createCSLL(self, nodeValue):
        node = Node(nodeValue)
        node.next = node
        self.head = node
        self.tail = node

    # Inserting in CSLL
    def insertCSLL(self, value, location):
        newNode = Node(value)
        if self.head is None:
            self.head = newNode
            self.tail = newNode
            newNode.next = newNode
        else:
            if location == 0:
                newNode.next = self.head
                self.head = newNode
                self.tail.next = newNode
            elif location == -1:
                newNode.next = self.tail.next
                self.tail.next = newNode
                self.tail = newNode
            else:
                tempNode = self.head
                index = 0
                while index < location-1:
                    tempNode = tempNode.next
                    index += 1
                nextNode = tempNode.next
                tempNode.next = newNode
                newNode.next = nextNode
                if tempNode == self.tail:
                    self.tail = newNode

    # Traversing through CSLL
    def traverseCSLL(self):
        if self.head is None:
            print("The Linked list is empty")
        else:
            node = self.head
            while node:
                print(node.value)
                node = node.next
                if node == self.tail.next:
                    break

    # Searching in CSLL
    def searchCSLL(self, key):
        if self.head is None:
            print("The Linked list is empty")
        else:
            currentNode = self.head
            index = 0
            while currentNode:
                if currentNode.value == key:
                    return index
                currentNode = currentNode.next
                index += 1
                if currentNode == self.tail.next:
                    return "The element is not in the Linked list"

    # Deleting element from CSLL
    def deleteNode(self, location):
        if self.head is None:
            print("The Linked list is empty")
        else:
            if location == 0:
                if self.head == self.tail:
                    self.head.next = None
                    self.head = None
                    self.tail = None
                else:
                    self.head = self.head.next
                    self.tail.next = self.head
            elif location == -1:
                if self.head == self.tail:
                    self.head.next = None
                    self.head = None
                    self.tail = None
                else:
                    node = self.head
                    while node is not None:
                        if node.next == self.tail:
                            break
                        node = node.next
                    node.next = self.head
                    self.tail = node
            else:
                tempNode = self.head
                index = 0
                while index < location - 1:
                    tempNode = tempNode.next
                    index += 1
                nextNode = tempNode.next
                tempNode.next = nextNode.next
                if nextNode == self.tail:
                    self.tail = tempNode

    # Deleting entire CSLL
    def deleteCSLL(self):
        self.head = None
        self.tail.next = None
        self.tail = None



# Creating CSLL
circularSLL = CircularSinglyLinkedList()
circularSLL.createCSLL(1)

# Inserting elements
circularSLL.insertCSLL(2,1)
circularSLL.insertCSLL(3,2)
circularSLL.insertCSLL(6,-1)
circularSLL.insertCSLL(4,3)
circularSLL.insertCSLL(5,4)
circularSLL.insertCSLL(0,0)

print([node.value for node in circularSLL])

# Traversing through CSLL
# circularSLL.traverseCSLL()

# Searching in CSLL
print(circularSLL.searchCSLL(6))

# Deleting in CSLL
circularSLL.deleteNode(3)
print([node.value for node in circularSLL])

# Deleting CSLL
circularSLL.deleteCSLL()
print([node.value for node in circularSLL])
