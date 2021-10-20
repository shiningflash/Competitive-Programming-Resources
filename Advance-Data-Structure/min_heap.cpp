#include <bits/stdc++.h>
using namespace std;

class MinHeap {

private:
    vector <int> heap;

    int parent(int n) {
        return (n - 1) >> 1;
    }

    int left(int n) {
        return (n << 1) + 1;
    }

    int right(int n) {
        return (n << 1) + 2;
    }

public:
    void push(int element) {
        heap.push_back(element);

        int i = heap.size() - 1;

        while (i != 0 && heap[i] < heap[parent(i)]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    int peek() {
        return heap[0];
    }

    int pop() {
        int head = heap[0];
        
        int size = heap.size();
        heap[0] = heap[size-1];
        heap.pop_back();

        min_heapify(0);

        return head;
    }

    void min_heapify(int pos) {
        int l = left(pos);
        int r = right(pos);

        int smallest = pos;

        if (l < heap.size() && heap[l] < heap[smallest]) smallest = l;
        if (r < heap.size() && heap[r] < heap[smallest]) smallest = r;

        if (smallest != pos) {
            swap(heap[smallest], heap[pos]);
            min_heapify(smallest);
        }
    }

    int size() {
        return heap.size();
    }
};

int main() {
    MinHeap h;
    
    h.push(12);
    h.push(1);
    h.push(9);
    h.push(21);

    cout << "size: " << h.size() << endl;

    cout << "popped: " << h.pop() << endl;
    cout << "popped: " << h.pop() << endl;
    cout << "popped: " << h.pop() << endl;
    cout << "popped: " << h.pop() << endl;
}

/*
size: 4
popped: 1
popped: 9
popped: 12
popped: 21
*/
