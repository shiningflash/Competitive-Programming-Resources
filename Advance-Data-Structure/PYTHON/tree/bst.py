class BinarySearchTreeNode:
    def __init__(self, data, left=None, right=None):
        self.data = data
        self.left = left
        self.right = right

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

    def delete(self, data):
        if not self:
            return None
        elif data < self.data:
            if self.left:
                self.left = self.left.delete(data)
        elif data > self.data:
            if self.right:
                self.right = self.right.delete(data)
        else:
            if not self.left and not self.right:
                return None
            if not self.left:
                return self.right
            if not self.right:
                return self.left

            # take minimum value from right subtree
            rightMinVal = self.right.findMin()
            self.data = rightMinVal
            self.right = self.right.delete(rightMinVal)
        return self

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


def printTree(tree):
    if not tree:
        print('Tree empty!!!')
        return

    print('pre order traversal: ', tree.preOrderTraversal())
    print('in order traversal: ', tree.inOrderTraversal())
    print('post order traversal: ', tree.postOrderTraversal())


def deleteAndCheck(tree, data):
    print('\ndeleting: ', data)
    if not tree:
        print('Tree empty!!!')
        return tree

    tree = tree.delete(data)
    printTree(tree)
    return tree


if __name__ == '__main__':
    elementList = [234, 12, 1, 3234, 23, 4, 1, 100]
    # elementList = [12]
    tree = buildTree(elementList)
    printTree(tree)
    print('search 12: ', tree.search(12))
    print('search 110: ', tree.search(110))
    print('min value: ', tree.findMin())
    print('max value: ', tree.findMax())
    print('sum of elements: ', sum(tree.inOrderTraversal()))
    tree = deleteAndCheck(tree, 12)
    tree = deleteAndCheck(tree, 123456)
    tree = deleteAndCheck(tree, 1)
    tree = deleteAndCheck(tree, 234)
    tree = deleteAndCheck(tree, 4)
    tree = deleteAndCheck(tree, 100)
    tree = deleteAndCheck(tree, 23)
    tree = deleteAndCheck(tree, 3234)
    tree = deleteAndCheck(tree, 12)
