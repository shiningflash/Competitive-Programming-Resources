from collections import deque

class Queue:
    def __init__(self):
        self.items = deque()
        
    def is_empty(self):
        return not self.items
    
    def enqueue(self, item):
        self.items.append(item)
    
    def dequeue(self):
        if self.is_empty():
            print('Queue empty...')
            raise SystemExit
        return self.items.popleft()
    
    def size(self):
        return len(self.items)
    
    def peek(self):
        if self.is_empty():
            print('Queue empty...')
            raise SystemExit
        return self.items[0]
    
    def __str__(self):
        return str(self.items)
    
if __name__ == '__main__':
    q = Queue()
    print(q)
    print(q.is_empty())
    q.enqueue(1)
    q.enqueue(2)
    print(q)
    print(q.dequeue())
    print(q.peek())
    print(q)
    print(q.dequeue())
    print(q.dequeue())