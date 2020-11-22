class Node:
    def __init__(self, value):
        self.value = value
        self.next = None

class List:
    def __init__(self):
        self.top_ = None
    
    def insertFront(self, value):
        tmp = Node(value)
        tmp.next = self.top_
        self.top_ = tmp
    
    def lastValue(self):
        etmp = self.top_.value
        return etmp

    def removeFront(self):
        self.top_ = self.top_.next

    def lprint(self):
        tmp = self.top_
        while tmp is not None:
            print(tmp.value)
            tmp = tmp.next

# Inheritance
class Stack(List):
    def push(self, value):
        self.insertFront(value)
    
    def top(self):
        return self.lastValue()

    def pop(self):
        self.removeFront()

    def sprint(self):
        self.lprint()

stack = Stack()
print('\nValores insertados en el stack: ')
stack.push(15)
stack.push(5.0)
stack.push(1)
stack.push('900')
stack.push(7.4)
stack.push(4.3)
stack.sprint()

value = stack.top()
print('\nValor top: ', value)

print('\nPop: ')
stack.pop()
stack.sprint()
