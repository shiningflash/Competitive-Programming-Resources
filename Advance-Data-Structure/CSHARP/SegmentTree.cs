using System;

public class SegmentTree {

    public void printArray(int[] a, int b, int e) {
        for (int i = b; i <= e; i++) {
            Console.Write("{0} ", a[i]);
        }
        Console.WriteLine();
    }

    public void init(int[] a, int[] tree, int node, int b, int e) {
        if (b == e) {
            tree[node] = a[b];
            return;
        }
        int left = node << 1;
        int right = left | 1;
        int mid = (b + e) >> 1;
        init(a, tree, left, b, mid);
        init(a, tree, right, mid+1, e);
        tree[node] = tree[left] + tree[right];
    }

    public int query(int[] a, int[] tree, int node, int b, int e, int i, int j) {
        if (i > j) return 0;
        if (i == b && j == e) return tree[node];
        int left = node << 1;
        int right = left | 1;
        int mid = (b+e) >> 1;
        int ls = query(a, tree, left, b, mid, i, Math.Min(mid, j));
        int rs = query(a, tree, right, mid+1, e, Math.Max(mid+1, i), j);
        return ls + rs;
    }

    public void update(int[] a, int[] tree, int node, int b, int e, int pos, int val) {
        if (b == e) {
            tree[node] = val;
            return;
        }
        int left = node << 1;
        int right = left | 1;
        int mid = (b + e) >> 1;
        if (pos <= mid) update(a, tree, left, b, mid, pos, val);
        else update(a, tree, right, mid+1, e, pos, val);
        tree[node] = tree[left] + tree[right];
    }

    public void manageSegmentTree() {
        string[] nq = Console.ReadLine().Split(' ');
        int n = Convert.ToInt32(nq[0]);
        int q = Convert.ToInt32(nq[1]);

        int[] a = new int[n+1];
        int[] tree = new int[4*(n+1)];

        string[] arr = Console.ReadLine().Split(' ');
        for (int i = 1; i <= arr.Length; i++) a[i] = Convert.ToInt32(arr[i-1]);

        init(a, tree, 1, 1, n);

        for (int i = 0; i < q; i++) {
            string[] xy = Console.ReadLine().Split(' ');
            int x = Convert.ToInt32(xy[0]);
            int y = Convert.ToInt32(xy[1]);
            Console.WriteLine(query(a, tree, 1, 1, n, x, y));
            // update(a, tree, 1, 1, n, x, y);
        }

        // printArray(a, 1, n);
    }
}