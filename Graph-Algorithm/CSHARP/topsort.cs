using System;
using System.Collections.Generic;

public class TopSort {
    
    int nodes, edges;
    List <int>[] graph;
    int[] vis;

    public TopSort() {

    }

    public void initTopSort(int nodes, int edges) {
        this.nodes = nodes;
        this.edges = edges;

        graph = new List<int>[nodes+1];
        vis = new int[nodes+1];

        for (int i = 1; i <= nodes; i++) {
            vis[i] = 0;
            graph[i] = new List<int>();
        }
    }

    public void topsort() {
        Queue <int> q = new Queue<int>();

        for (int i = 1; i <= nodes; i++) {
            if (vis[i] == 0) {
                q.Enqueue(i);
            }
        }

        while (q.Count > 0) {
            int u = q.Dequeue();
            Console.Write("{0} ", u);

            for (int i = 0; i < graph[u].Count; i++) {
                int v = graph[u][i];
                vis[v]--;

                if (vis[v] == 0) {
                    q.Enqueue(v);
                }
            }
        }
    }

    public void manageTopSort(string[] lines) {
        string[] line1 = lines[0].Split(' ');
        int nodes = int.Parse(line1[0]);
        int edges = int.Parse(line1[1]);

        initTopSort(nodes, edges);

        for (int i = 1; i <= edges; i++) {
            string[] all_edge = lines[i].Split(' ');
            int u = int.Parse(all_edge[0]);
            int v = int.Parse(all_edge[1]);
            graph[u].Add(v);
            vis[v]++;
        }

        topsort();

        Console.WriteLine();
    }
}