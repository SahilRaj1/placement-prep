""" Doubly Linked List """

class Node:
    def __init__(self, value):
        self.value = value
        self.next = None
        self.prev = None

class DoublyLinkedList:
    def __init__(self):
        self.head = None
        self.tail = None

    def __iter__(self):
        node = self.head
        while node:
            yield node
            node = node.next

    # Creating a DLL
    def createDLL(self,nodeValue):
        node = Node(nodeValue)
        self.head = node
        self.tail = node

    def insertNode(self,value, location):
        newNode = Node(value)
        if self.head is None:
            self.head = newNode
            self.tail = newNode
        else:
            if location == 0:
                newNode.next = self.head
                self.head.prev = newNode
                self.head = newNode
            elif location == -1:
                newNode.prev = self.tail
                self.tail.next = newNode
                self.tail = newNode
            else:
                tempNode = self.head
                index = 0
                while index < location - 1:
                    tempNode = tempNode.next
                    index += 1
                if tempNode == self.tail:
                    newNode.prev = self.tail
                    self.tail.next = newNode
                    self.tail = newNode
                else:
                    nextNode = tempNode.next
                    newNode.next = nextNode
                    newNode.prev = tempNode
                    tempNode.next = newNode
                    nextNode.prev = newNode

    # traversing in DLL
    def traverseDLL(self):
        if self.head == None:
            print("The DLL is empty")
        else:
            tempNode = self.head
            while tempNode:
                print(tempNode.value)
                tempNode = tempNode.next

    # reverse traversing
    def revTraverse(self):
        if self.head == None:
            print("The DLL is empty")
        else:
            tempNode = self.tail
            while tempNode:
                print(tempNode.value)
                tempNode = tempNode.prev

    # searching in DLL
    def searchDLL(self, nodeValue):
        if self.head == None:
            print("The DLL is empty")
        else:
            tempNode = self.head
            while tempNode:
                if tempNode.value == nodeValue:
                    return "The element is in the DLL"
                tempNode = tempNode.next
            return "The element does not exist in the DLL"

    # deleting in DLL
    def deleteNode(self, location):
        if self.head is None:
            print("The linked List is empty")
        else:
            if location == 0:
                if self.head == self.tail:
                    self.head = None
                    self.tail = None
                else:
                    self.head = self.head.next
                    self.head.prev = None
            elif location == -1:
                if self.head == self.tail:
                    self.head = None
                    self.tail = None
                else:
                    self.tail = self.tail.prev
                    self.tail.next = None
            else:
                tempNode = self.head
                index = 0
                while index < location-1:
                    tempNode = tempNode.next
                    index += 1
                tempNode.next = tempNode.next.next
                tempNode.next.prev = tempNode

    # deleting a DLL
    def deleteDLL(self):
        if self.head is None:
            print("The linked list is empty")
        else:
            tempNode = self.head
            while tempNode:
                tempNode.prev = None
                tempNode = tempNode.next
            self.head = None
            self.tail = None


# Creating a DLL
DLL = DoublyLinkedList()
DLL.createDLL(1)

# Inserting in DLL
DLL.insertNode(2,1)
DLL.insertNode(3,2)
DLL.insertNode(5,-1)
DLL.insertNode(0,0)
DLL.insertNode(4,4)

print([node.value for node in DLL])

# traversing in DLL
# DLL.traverseDLL()

# reverse traversing
DLL.revTraverse()

# searching DLL
print(DLL.searchDLL(4))

# deleting in DLL
DLL.deleteNode(3)
print([node.value for node in DLL])

# deleting DLL
DLL.deleteDLL()


dll2 = DoublyLinkedList()
dll2.insertnode(5)