class Node:
    def __init__(self, value):
        self.value = value
        self.next = None

class List:
    def __init__(self):
        self.front_ = self.rear_ = None
    
    def isEmpty(self):
        return self.front_ == None

    def insert(self, value):
        tmp = Node(value)
        if self.rear_ == None:
            self.front_ = self.rear_ = tmp
            return
        self.rear_.next = tmp
        self.rear_ = tmp
    
    def removeFront(self):
        if self.isEmpty(): return
        etmp = self.front_
        self.front_ = etmp.next
        if (self.front_ == None):
            self.rear_ = None

    def lprint(self):
        tmp = self.front_
        while tmp is not None:
            print(tmp.value)
            tmp = tmp.next

# Inheritance
class Queue(List):
    def enQueue(self, value):
        self.insert(value)
    
    def front(self):
        return self.front_.value

    def deQueue(self):
        self.removeFront()

    def qprint(self):
        self.lprint()

queue = Queue()
print('\nValores insertados en la cola: ')
queue.enQueue(15)
queue.enQueue(5.0)
queue.enQueue(1)
queue.enQueue('900')
queue.enQueue(7.4)
queue.enQueue(4.3)
queue.qprint()

value = queue.front()
print('\nPrimer Valor de la cola: ', value)

print('\nDelete: ')
queue.deQueue()
queue.qprint()

value = queue.front()
print('\nPrimer Valor de la cola: ', value)
