""" Queue using Linked List"""

class Node:
    def __init__(self, value):
        self.value = value
        self.next = None
        
    def __str__(self):
        return str(self.value)

class LinkedList:
    def __init__(self):
        self.head = None
        self.tail = None

    def __iter__(self):
        node = self.head
        while node:
            yield node
            node = node.next


class Queue:
    def __init__(self):
        self.queue = LinkedList()

    def __str__(self):
        values = [str(x) for x in self.queue]
        return "[" + " ".join(values) + "]"

    def enqueue(self, value):
        newNode = Node(value)
        if self.queue.head is None:
            self.queue.head = newNode
            self.queue.tail = newNode
        else:
            self.queue.tail.next = newNode
            self.queue.tail = newNode

    def isEmpty(self):
        if self.queue.head is None:
            return True
        else:
            return False

    def dequeue(self):
        if self.isEmpty():
            print("The queue is empty")
        else:
            value = self.queue.head.value
            if self.queue.head == self.queue.tail:
                self.queue.head = None
                self.queue.tail = None
            else:
                self.queue.head = self.queue.head.next
            return value

    def peek(self):
        if self.isEmpty():
            print("The queue is empty")
        else:
            print(self.queue.head.value)

    def delete(self):
        self.queue.head = None
        self.queue.tail = None


q = Queue()
q.enqueue(1)
q.enqueue(2)
q.enqueue(3)
q.enqueue(4)

print(q)

q.dequeue()
print(q)

q.peek()
q.delete()
