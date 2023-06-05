""" Queue using python list no size limit"""

class Queue:
    def __init__(self):
        self.queue = []

    def __str__(self):
        values = [str(item) for item in self.queue]
        return "[" + " ".join(values) + "]"

    def isEmpty(self):
        if self.queue == []:
            return True
        else:
            return False

    def enqueue(self, value):
        self.queue.append(value)

    def dequeue(self):
        if self.isEmpty():
            print("The queue is empty")
        else:
            return self.queue.pop(0)

    def peek(self):
        if self.isEmpty():
            print("The queue is empty")
        else:
            return self.queue[0]

    def delete(self):
        self.queue = None


q = Queue()
q.isEmpty()
q.enqueue(1)
q.enqueue(2)
q.enqueue(3)
q.enqueue(4)
print(q)

q.dequeue()
print(q)

print(q.peek())
q.delete()
