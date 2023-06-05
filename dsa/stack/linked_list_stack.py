""" Stack using Linked List"""

class Node:
    def __init__(self, value=None):
        self.value = value
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None

    def __iter__(self):
        node = self.head
        while node:
            yield node
            node = node.next

class Stack:
    def __init__(self):
        self.LinkedList = LinkedList()

    def display(self):
        values = [node.value for node in self.LinkedList]
        print(values[::-1])

    def isEmpty(self):
        if self.LinkedList.head is None:
            return True
        else:
            return False

    def push(self, value):
        node = Node(value)
        node.next = self.LinkedList.head
        self.LinkedList.head = node

    def pop(self):
        if self.isEmpty():
            print("Stack Underflow")
        else:
            value = self.LinkedList.head.value
            self.LinkedList.head = self.LinkedList.head.next
            return value

    def peek(self):
        if self.isEmpty():
            print("Stack Underflow")
        else:
            value = self.LinkedList.head.value
            print(value)

    def delete(self):
        self.LinkedList.head = None


s = Stack()
print(s.isEmpty())

s.push(1)
s.push(2)
s.push(3)
s.push(4)
s.display()

s.pop()
s.display()

s.peek()

s.delete()
