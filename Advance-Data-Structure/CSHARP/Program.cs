using System;
using System.Collections.Generic;

public class Program {
    public static void Main(string[] args) {
        string[] lines = System.IO.File.ReadAllLines("in.txt");

        // MapExercise me = new MapExercise();
        // me.run(lines);

        // PriorityQueue<int> pq = new PriorityQueue<int>();
        // pq.Add(12, 12);
        // pq.Add(13, 13);
        // pq.Add(2, 2);
        // Console.WriteLine(pq.RemoveMin());
        // Console.WriteLine(pq.Peek());
        // Console.WriteLine(pq.RemoveMin());
        // Console.WriteLine(pq.RemoveMin());

        // CustomSort cs = new CustomSort();
        // cs.manageCustomSort(lines);

        // SegmentTree sg = new SegmentTree();
        // sg.manageSegmentTree();

        // string s = "Faizun Faria";
        // char[] sc = s.ToCharArray();
        // int[] occ = new int[26];
        // for (int i = 0; i < 26; i++) occ[i] = 0;
        // for (int i = 0; i < sc.Length; i++) {
        //     if (sc[i] == ' ') continue;
        //     if (sc[i] >= 'A' && sc[i] <= 'Z') sc[i] = (char) ((int) sc[i] - (int) 'A' + (int) 'a');
        //     occ[(int) sc[i] - (int) 'a']++;
        // }
        // for (int i = 0; i < 26; i++) {
        //     if (occ[i] > 0) {
        //         Console.WriteLine("{0} {1}", (char) (i + (int) 'a'), occ[i]);
        //     }
        // }

        BinarySearchTree bst = new BinarySearchTree();
        bst.manageBinarySearch();
    }
}