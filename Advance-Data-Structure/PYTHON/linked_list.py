class Node:
    def __init__(self, data=None):
        self.data = data
        self.next = None


class LinkedList:
    def __init__(self):
        self.head = None

    def insertAtBeginning(self, data):
        new_node = Node(data)
        new_node.next = self.head
        self.head = new_node

    def insertAtEnd(self, data):
        new_node = Node(data)

        if not self.head:
            self.head = new_node
            return

        curr = self.head
        while curr.next:
            curr = curr.next

        curr.next = new_node

    def search(self, data):
        if not self.head:
            print('List is empty!')

        curr = self.head
        while curr:
            if curr.data == data:
                return True
            curr = curr.next
        return False

    def deleteNode(self, position):
        if not self.head:
            return

        curr = self.head

        if position == 0:
            self.head = curr.next
            curr = None
            return

        for i in range(position-1):
            curr = curr.next
            if not curr:
                return

        if not curr.next:
            return

        next_node = curr.next.next
        curr.next = None
        curr.next = next_node

    def printList(self):
        if not self.head:
            print('List is empty!')
            return

        curr = self.head
        while curr:
            print(curr.data, end=' --> ')
            curr = curr.next
        print()


if __name__ == '__main__':
    llist = LinkedList()
    print(llist.search(1))
    llist.printList()
    llist.insertAtBeginning(1)
    print(llist.search(1))
    print(llist.search(2))
    llist.printList()
    llist.insertAtBeginning(3)
    llist.insertAtBeginning(7)
    llist.printList()
    llist.insertAtEnd(-1)
    llist.insertAtEnd(-17)
    llist.printList()
    llist.deleteNode(0)
    llist.printList()
    llist.deleteNode(7)
    llist.printList()
    llist.deleteNode(2)
    llist.printList()
    llist.deleteNode(2)
    llist.printList()
