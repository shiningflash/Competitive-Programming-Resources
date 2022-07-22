# Priority Queue Implementation using Python

class PriorityQueue:
    def __init__(self):
        self.arr = []

    def getLength(self):
        return len(self.arr)

    def leftChild(self, pos):
        return 2 * pos + 1

    def rightChild(self, pos):
        return 2 * pos + 2

    def getPosition(self, val):
        pos = 0
        for pos in range(self.getLength()):
            if self.arr[pos] == val:
                break
        return pos

    def swap(self, pos1, pos2):
        self.arr[pos1], self.arr[pos2] = self.arr[pos2], self.arr[pos1]

    def heapify(self, n, pos):
        largest = pos
        left = self.leftChild(pos)
        right = self.rightChild(pos)

        if left < n and self.arr[left] > self.arr[largest]:
            largest = left
        if right < n and self.arr[right] > self.arr[largest]:
            largest = right

        # swap and continue heapify if root is not largest
        if largest != pos:
            self.swap(pos, largest)
            self.heapify(n, largest)

    def callHeapify(self):
        sz = self.getLength()
        if sz > 1:
            for i in range((sz // 2) - 1, -1, -1):
                self.heapify(sz, i)

    def insert(self, newVal):
        self.arr.append(newVal)
        self.callHeapify()

    def delete(self, val):
        sz = self.getLength()
        pos = self.getPosition(val)

        self.swap(pos, sz-1)
        self.arr.pop()
        self.callHeapify()

    def pop(self):
        maxval = self.arr[0]
        sz = self.getLength()
        self.swap(0, sz-1)
        self.arr.pop()
        self.callHeapify()
        return maxval

    def printHeap(self):
        for x in self.arr:
            print(x, end=' ')
        print()


if __name__ == '__main__':
    q = PriorityQueue()
    q.insert(100)
    q.insert(0)
    q.insert(50)
    q.insert(10)
    x = q.pop()
    print(x)  # print 100
    x = q.pop()
    print(x)  # print 50
