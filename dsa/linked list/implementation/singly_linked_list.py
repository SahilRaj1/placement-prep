""" Singly Linked List """

class Node:
    def __init__(self, value=None):
        self.value = value
        self.next = None

class SLinkedList:
    def __init__(self):
        self.head = None
        self.tail = None

    def __iter__(self):
        node = self.head
        while node:
            yield node
            node = node.next

    # Inserting a Node
    def insertNode(self, value, location):
        newNode = Node(value)
        if self.head is None:
            self.head = newNode
            self.tail = newNode
        else:
            if location == 0:
                newNode.next = self.head
                self.head = newNode
            elif location == -1:
                self.tail.next = newNode
                self.tail = newNode
            else:
                tempNode = self.head
                index = 0
                while index < location-1:
                    tempNode = tempNode.next
                    index+=1
                nextNode = tempNode.next
                tempNode.next = newNode
                newNode.next = nextNode
                if tempNode == self.tail:
                    self.tail = newNode

    # Traversing through the Linked List
    def traverseSLL(self):
        if self.head is None:
            print("The linked list is empty")
        else:
            node = self.head
            while node is not None:
                print(node.value)
                node = node.next

    # Searching in Linked List
    def searchSLL(self, key):
        if self.head is None:
            return "The Linked List is empty"
        else:
            node = self.head
            while node is not None:
                if node.value == key:
                    return "This is present in the linked list"
                node = node.next
            return "This is not present in the Linked List"

    # Deleting in Linked List
    def deleteNode(self, location):
        if self.head is None:
            print("The Linked List is empty")
        else:
            if location==0:
                if self.head == self.tail:
                    self.head = None
                    self.tail = None
                else:
                    self.head = self.head.next
            elif location==-1:
                if self.head == self.tail:
                    self.head = None
                    self.tail = None
                else:
                    node = self.head
                    while node.next is not None:
                        if node.next == self.tail:
                            break
                        node = node.next
                    node.next = None
                    self.tail = node
            else:
                tempNode = self.head
                index = 0
                while index < location-1:
                    tempNode = tempNode.next
                    index += 1
                nextNode = tempNode.next
                tempNode.next = nextNode.next

    # Delete an entire Linked List
    def deleteSLL(self):
        if self.head is None:
            print("The Linked list is empty")
        else:
            self.head = None
            self.tail = None


singlyLinkedList = SLinkedList()
singlyLinkedList.insertNode(1, 1)
singlyLinkedList.insertNode(2, 1)
singlyLinkedList.insertNode(3, 2)
singlyLinkedList.insertNode(4, 3)
singlyLinkedList.insertNode(0, 0)
singlyLinkedList.insertNode(5, -1)


print([node.value for node in singlyLinkedList])
# singlyLinkedList.traverseSLL()

# print(singlyLinkedList.searchSLL(3))

singlyLinkedList.deleteNode(3)
print([node.value for node in singlyLinkedList])

singlyLinkedList.deleteSLL()
print([node.value for node in singlyLinkedList])
