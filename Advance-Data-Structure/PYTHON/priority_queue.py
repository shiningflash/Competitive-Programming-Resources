import heapq

class PriorityQueue:
    def __init__(self):
        self.elements = []
        
    def is_empty(self):
        return not self.elements
    
    def put(self, item, priority):
        heapq.heappush(self.elements, (priority, item))
        
    def get(self):
        if self.is_empty():
            print('Priority queue empty...')
            raise SystemExit
        return heapq.heappop(self.elements)[1]
    
    def __str__(self):
        return str(self.elements)
    
if __name__ == '__main__':
    q = PriorityQueue()
    print(q)
    q.put('amirul', 100)
    q.put('samiul', 45)
    print(q)
    q.put('faria', 78)
    print(q)
    print(q.get())
    print(q.get())
    print(q.get())
    print(q.get())