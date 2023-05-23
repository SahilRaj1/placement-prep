""" Circular Doubly Linked List """

class Node:
    def __init__(self, value):
        self.value = value
        self.next = None
        self.prev = None

class CircularDoublyLinkedList:
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

    # creating a CDLL
    def createCDLL(self, nodeValue):
        newNode = Node(nodeValue)
        self.head = newNode
        self.tail = newNode
        newNode.next = newNode
        newNode.prev = newNode

    # inserting in CDLL
    def insertNode(self, value, location):
        newNode = Node(value)
        if self.head is None:
            self.head = newNode
            self.tail = newNode
            newNode.next = newNode
            newNode.prev = newNode
        else:
            if location == 0:
                newNode.next = self.head
                newNode.prev = self.tail
                self.head.prev = newNode
                self.tail.next = newNode
                self.head = newNode
            elif location == -1:
                newNode.prev = self.tail
                newNode.next = self.head
                self.head.prev = newNode
                self.tail.next = newNode
                self.tail = newNode
            else:
                tempNode = self.head
                index = 0
                while index < location-1:
                    tempNode = tempNode.next
                    index += 1
                nextNode = tempNode.next
                newNode.prev = tempNode
                newNode.next = nextNode
                tempNode.next = newNode
                nextNode.prev = newNode
                if tempNode == self.tail:
                    self.tail = newNode

    # traverse through CDLL
    def traverseCDLL(self):
        node = self.head
        while node:
            print(node.value)
            node = node.next
            if node == self.tail.next:
                break

    # reverse traversal through CDLL
    def revtraverseCDLL(self):
        node = self.tail
        while node:
            print(node.value)
            node = node.prev
            if node == self.head.prev:
                break

    # searching in CDLL
    def searchCDLL(self, key):
        tempNode = self.head
        while tempNode:
            if tempNode.value == key:
                return True
            tempNode = tempNode.next
            if tempNode == self.tail.next:
                break
        return False

    # deleting node from CDLL
    def deleteNode(self, location):
        if self.head is None:
            print("The Linked list is empty")
        else:
            if location == 0:
                if self.head == self.tail:
                    self.head.next = None
                    self.head.prev = None
                    self.head = None
                    self.tail = None
                else:
                    self.head = self.head.next
                    self.head.prev = self.tail
                    self.tail.next = self.head
            elif location == -1:
                if self.head == self.tail:
                    self.head.next = None
                    self.head.prev = None
                    self.head = None
                    self.tail = None
                else:
                    self.tail = self.tail.prev
                    self.tail.next = self.head
                    self.head.prev = self.tail
            else:
                tempNode = self.head
                index = 0
                while index < location-1:
                    tempNode = tempNode.next
                    index += 1
                if tempNode.next == self.tail:
                    self.tail = tempNode
                tempNode.next = tempNode.next.next
                tempNode.next.prev = tempNode

    # deleting CDLL
    def deleteCDLL(self):
        if self.head == None:
            print("The linked list is empty")
        else:
            self.tail.next = None
            node = self.head
            while node:
                node.prev = None
                node = node.next
            self.head = None
            self.tail = None


# creating a CDLL
CDLL = CircularDoublyLinkedList()
CDLL.createCDLL(2)
# print([node.value for node in CDLL])

# inserting node in CDLL
CDLL.insertNode(1,0)
CDLL.insertNode(0,0)
CDLL.insertNode(5,-1)
CDLL.insertNode(3,3)
CDLL.insertNode(4,4)
print([node.value for node in CDLL])

# traversing through CDLL
# CDLL.traverseCDLL()

# reverse traversing through CDLL
# CDLL.revtraverseCDLL()

# searching in CDLL
print(CDLL.searchCDLL(4))

# deleting node in CDLL
CDLL.deleteNode(5)
print([node.value for node in CDLL])

# deleting CDLL
CDLL.deleteCDLL()
print([node.value for node in CDLL])
