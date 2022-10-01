
class Node:
    def __init__(self, data):
       self.data = data
       self.next = None
 
class Stack:
    def __init__(self):
        self.head = None
 
    def push(self, data):
        if self.head is None:
            self.head = Node(data)
        else:
            new_node = Node(data)
            new_node.next = self.head
            self.head = new_node
 
    def pop(self):
        if self.head is None:
            return None
        else:
            popped = self.head.data
            self.head = self.head.next
            return popped
    def peek(self):
        if self.head is None:
            return None
        else:
            peeked = self.head.data
            return peeked
    
    def print_stack(self):
        print_int = self.head
        while print_int is not None:
            print(print_int.data)
            print_int = print_int.next
            
a_stack = Stack()
while True:
    print('push <value>')
    print('pop')
    print('peek')
    print('print')
    print('quit')
    do = input('What would you like to do? ').split()
 
    operation = do[0].strip().lower()
    if operation == 'push':
        a_stack.push(int(do[1]))
    elif operation == 'pop':
        popped = a_stack.pop()
        if popped is None:
            print('Stack is empty.')
        else:
            print('Popped value: ', int(popped))
    elif operation == 'peek':
        peeked = a_stack.pop()
        if peeked is None:
            print('Stack is empty.')
        else:
            print('Peeked value: ', int(peeked))
    elif operation == 'print':
        a_stack.print_stack()
        
    elif operation == 'quit':
        break
