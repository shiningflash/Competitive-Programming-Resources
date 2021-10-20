#include <bits/stdc++.h>
using namespace std;
#define SIZE 10

template <class Type>
class Queue {

private:
    Type *arr;
    int head;
    int tail;
    int capacity;

public:
    Queue(int size) {
        arr = new Type[size];
        head = 0;
        tail = 0;
        capacity = size;
    }

    void enqueue(Type item) {
        if (isFull()) {
            printf("Error, stack is full\n");
            exit(EXIT_FAILURE);
        }
        arr[tail] = item;
        tail = (tail+1) % capacity;
    }

    Type dequeue() {
        if (isEmpty()) {
            printf("Error, stack is empty\n");
            exit(EXIT_FAILURE);
        }
        Type item = arr[head];
        head = (head + 1) % capacity;
        return item;
    }

    bool isFull() {
        return ((tail + 1) % capacity == head);
    }

    bool isEmpty() {
        return head == tail;
    }
};

int main() {
    Queue <string> q(5);
    
    q.enqueue("brac");
    q.enqueue("aiub");
    q.enqueue("du");
    
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
}
