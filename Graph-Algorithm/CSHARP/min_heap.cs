// using System;

// class MinHeap {
//     public int[] heapArray { get; set; }
//     public int capacity { get; set; }
//     public int curHeapSize { get; set; }

//     public MinHeap(int n) {
//         capacity = n;
//         heapArray = new int[capacity];
//         curHeapSize = 0;
//     }

//     public static void Swap<T>(ref T x, ref T y) {
//         T temp = x;
//         x = y;
//         y = temp;
//     }

//     public int Parent(int n) {
//         return (n - 1) / 2;
//     }

//     public int Left(int n) {
//         return 2 * n + 1;
//     }

//     public int Right(int n) {
//         return 2 * n + 2;
//     }

//     public void decreaseVal(int pos, int val) {
//         heapArray[pos] = val;
//         while (pos != 0 && heapArray[pos] < heapArray[Parent(pos)]) {
//             Swap(ref heapArray[pos], ref heapArray[Parent(pos)]);
//             pos = Parent(pos);
//         }
//     }

//     public bool Push(int val) {
//         // Heap size full
//         if (curHeapSize == capacity) {
//             return false;
//         }
//         // push to heap
//         int i = curHeapSize;
//         heapArray[curHeapSize] = val;
//         curHeapSize++;

//         // fix heap property
//         while (i != 0 && heapArray[i] < heapArray[Parent(i)]) {
//             Swap(ref heapArray[i], ref heapArray[Parent(i)]);
//             i = Parent(i);
//         }
//         return true;
//     }

//     public void MinHeapify(int pos) {
//         int l = Left(pos);
//         int r = Right(pos);

//         int smallest = pos;

//         if (l < curHeapSize && heapArray[l] < heapArray[smallest]) {
//             smallest = l;
//         }
//         if (r < curHeapSize && heapArray[r] < heapArray[smallest]) {
//             smallest = r;
//         }
//         if (smallest != pos) {
//             Swap(ref heapArray[pos], ref heapArray[smallest]);
//             MinHeapify(smallest);
//         }
//     }

//     public int Top() {
//         return heapArray[0];
//     }

//     public int Pop() {
//         if (curHeapSize <= 0) {
//             return int.MaxValue;
//         }
//         if (curHeapSize == 1) {
//             curHeapSize--;
//             return heapArray[0];
//         }

//         int root = heapArray[0];

//         heapArray[0] = heapArray[curHeapSize-1];
//         curHeapSize--;
//         MinHeapify(0);

//         return root;
//     }

//     public void DeleteVal(int pos) {
//         decreaseVal(pos, int.MinValue);
//         Pop();
//     }
// }