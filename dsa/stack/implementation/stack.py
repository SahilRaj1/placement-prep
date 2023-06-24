""" Stack with size limit using list"""

class Stack:
    def __init__(self, max):
        self.max = max
        self.list = []

    # display
    def display(self):
        print(self.list)

    # check if stack is empty
    def isEmpty(self):
        if self.list == []:
            return True
        else:
            return False

    # check if stack is full
    def isFull(self):
        if len(self.list) == self.max:
            return True
        else:
            return False

    # push
    def push(self, value):
        if self.isFull():
            print("Stack Overflow")
        else:
            self.list.append(value)

    # pop
    def pop(self):
        if self.isEmpty():
            print("Stack Underflow")
        else:
            return self.list.pop()

    # peek
    def peek(self):
        if self.isEmpty():
            print("Stack Underflow")
        else:
            return self.list[len(self.list)-1]

    # delete stack
    def delete(self):
        self.list = None


s = Stack(5)
print(s.isEmpty())

s.push(1)
s.push(2)
s.push(3)
s.push(4)
s.push(5)
s.display()

print(s.isFull())

s.pop()
s.display()

s.delete()
