class BinarySearchTreeNode:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

    def insert(self, data):
        if self.data == data:
            return

        if data < self.data:
            if self.left:
                self.left.insert(data)
            else:
                self.left = BinarySearchTreeNode(data)
        else:
            if self.right:
                self.right.insert(data)
            else:
                self.right = BinarySearchTreeNode(data)

    def search(self, data):
        if self.data == data:
            return True

        if data < self.data:
            if self.left:
                return self.left.search(data)
            else:
                return False
        elif data > self.data:
            if self.right:
                return self.right.search(data)
            else:
                return False

    def inOrderTraversal(self):
        element = []
        if self.left:
            element += self.left.inOrderTraversal()
        element.append(self.data)
        if self.right:
            element += self.right.inOrderTraversal()
        return element

    def preOrderTraversal(self):
        element = []
        element.append(self.data)
        if self.left:
            element += self.left.preOrderTraversal()
        if self.right:
            element += self.right.preOrderTraversal()
        return element

    def postOrderTraversal(self):
        element = []
        if self.left:
            element += self.left.postOrderTraversal()
        if self.right:
            element += self.right.postOrderTraversal()
        element.append(self.data)
        return element

    def findMin(self):
        if not self.left:
            return self.data
        return self.left.findMin()

    def findMax(self):
        if not self.right:
            return self.data
        return self.right.findMax()


def buildTree(elementList):
    if not elementList:
        return None

    root = BinarySearchTreeNode(elementList[0])
    for pos in range(1, len(elementList)):
        root.insert(elementList[pos])
    return root


if __name__ == '__main__':
    elementList = [234, 12, 1, 3234, 23, 4, 1, 100]
    tree = buildTree(elementList)
    print('pre order traversal: ', tree.preOrderTraversal())
    print('in order traversal: ', tree.inOrderTraversal())
    print('post order traversal: ', tree.postOrderTraversal())
    print('search 12: ', tree.search(12))
    print('search 110: ', tree.search(110))
    print('min value: ', tree.findMin())
    print('max value: ', tree.findMax())
    print('sum of elements: ', sum(tree.inOrderTraversal()))
