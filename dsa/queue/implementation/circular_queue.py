""" Circular Queue"""

class Queue:
    def __init__(self, max_size):
        self.items = max_size * [None]
        self.max_size = max_size
        self.front = -1
        self.rear = -1

    def __str__(self):
        values = [str(item) for item in self.items if item is not None]
        return "[" + " ".join(values) + "]"

    def isFull(self):
        if self.rear + 1 == self.front:
            return True
        elif self.front == 0 and self.rear == self.max_size-1:
            return True
        else:
            return False

    def isEmpty(self):
        if self.rear == -1:
            return True
        else:
            return False

    def enqueue(self, value):
        if self.isFull():
            print("The queue is Full")
        else:
            if self.rear == self.max_size-1:
                self.rear = 0
            else:
                self.rear += 1
                if self.front == -1:
                    self.front = 0
            self.items[self.rear] = value

    def dequeue(self):
        if self.isEmpty():
            print("The queue is empty")
        else:
            first_element = self.items[self.front]
            front = self.front
            if self.front == self.rear:
                self.front = -1
                self.rear = -1
            elif self.front == self.max_size-1:
                self.front = 0
            else:
                self.front += 1
            self.items[front] = None
            return first_element
        
    def peek(self):
        if self.isEmpty():
            print("The queue is empty")
        else:
            return self.items[self.front]

    def delete(self):
        self.items = self.max_size * [None]
        self.front = -1
        self.rear = -1


q = Queue(6)
q.enqueue(1)
q.enqueue(2)
q.enqueue(3)
q.enqueue(4)
print(q)

q.dequeue()
print(q)

print(q.peek())

q.delete()
