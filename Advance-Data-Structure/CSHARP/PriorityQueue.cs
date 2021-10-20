using System;
using System.Collections.Generic;

class MinHeap<T> where T : IComparable<T> {
    private List <T> heap = new List<T>();

    private int Parent(int n) {
        return (n - 1) / 2;
    }

    private int Left(int n) {
        return 2 * n + 1;
    }

    private int Right(int n) {
        return 2 * n + 2;
    }

    public void Add(T element) {
        heap.Add(element);

        int i = heap.Count - 1;

        while (i != 0 && heap[i].CompareTo(heap[Parent(i)]) == -1) {
            T temp = heap[i];
            heap[i] = heap[Parent(i)];
            heap[Parent(i)] = temp;

            i = Parent(i);
        }
    }

    public T Peek() {
        return heap[0];
    }

    public T RemoveMin() {
        T root = heap[0];

        int size = heap.Count;
        heap[0] = heap[size-1];
        heap.RemoveAt(size-1);

        MinHeapify(0);

        return root;
    }

    public void MinHeapify(int pos) {
        int l = Left(pos);
        int r = Right(pos);

        int smallest = pos;

        if (l < heap.Count && heap[l].CompareTo(heap[smallest]) == -1) {
            smallest = l;
        }
        if (r < heap.Count && heap[r].CompareTo(heap[smallest]) == -1) {
            smallest = r;
        }

        if (smallest != pos) {
            T temp = heap[smallest];
            heap[smallest] = heap[pos];
            heap[pos] = temp;

            MinHeapify(smallest);
        }
    }

    public int Count() {
        return heap.Count;
    }
}

public class PriorityQueue<T> {
    internal class Node : IComparable<Node> {
        public int priority;
        public T obj;

        public int CompareTo(Node other) {
            return priority.CompareTo(other.priority);
        }
    }

    private MinHeap <Node> minHeap = new MinHeap<Node>();

    public void Add(T element, int prior) {
        minHeap.Add(new Node() {
            obj = element,
            priority = prior
        });
    }

    public T Peek() {
        return minHeap.Peek().obj;
    }

    public T RemoveMin() {
        return minHeap.RemoveMin().obj;
    }

    public int Count() {
        return minHeap.Count();
    }
}