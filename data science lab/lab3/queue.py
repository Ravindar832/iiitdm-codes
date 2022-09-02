class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
        

class Queue:
    def __init__(self, data):
        new_node = Node(data)
        self.first = new_node
        self.last = new_node
        self.length = 1

    def print_queue(self):
        temp = self.first
        while temp is not None:
            print(temp.data)
            temp = temp.next
    def __init__(self):
        self.head = None
        self.last = None
 
    def enqueue(self, data):
        if self.last is None:
            self.head = Node(data)
            self.last = self.head
        else:
            self.last.next = Node(data)
            self.last = self.last.next
 
    def dequeue(self):
        if self.head is None:
            return None
        else:
            to_return = self.head.data
            self.head = self.head.next
            return to_return    
    
    def peek(self):
        if self.first is None:
            return None
        else:
            peeked = self.first.data
            return peeked
a_queue = Queue
while True:    
    print('enqueue <value>')  
    print('dequeue')  
    print('peek')
    print('print')    
    print('Exit')  
    do = input('What would you like to do? ').split()
 
    operation = do[0].strip().lower()
    if operation == 'enqueue':
        a_queue.enqueue(int(do[1]))
    elif operation == 'dequeue':
        dequeued = a_queue.dequeue()
        if dequeued is None:
            print('Queue is empty.')
        else:
            print('Dequeued element: ', int(dequeued))
    elif operation == 'quit':
        break