using System;
using System.Collections;
using System.Collections.Generic;

public class BFS {
    
    public int nodes, edges;
    public List <int>[] graph;
    public bool[] vis;

    public BFS() {

    }

    public void initBFS(int nodes, int edges) {
        this.nodes = nodes;
        this.edges = edges;

        graph = new List<int>[nodes];
        vis = new bool[nodes];
        
        for (int i = 0; i < nodes; i++) {
            graph[i] = new List<int>();
        }
    }

    public void bfs(int u) {
        Queue <int> q = new Queue<int>();
        q.Enqueue(u);
        vis[u] = true;

        while (q.Count > 0) {
            u = q.Dequeue();
            Console.Write("{0} ", u);

            for (int i = 0; i < graph[u].Count; i++) {
                int v = graph[u][i];
                if (vis[i] == false) {
                    q.Enqueue(v);
                    vis[v] = true;
                }
            }
        }
    }

    public void manageBFS(string[] lines) {
        
        string[] line1 = lines[0].Split(' ');
        int nodes = int.Parse(line1[0]);
        int edges = int.Parse(line1[1]);

        initBFS(nodes, edges);

        for (int i = 1; i <= edges; i++) {
            string[] all_edge = lines[i].Split(' ');
            int u = int.Parse(all_edge[0]);
            int v = int.Parse(all_edge[1]);
            graph[u].Add(v);
        }

        for (int i = 0; i < nodes; i++) {
            if (vis[i] == false) {
                bfs(i);
            }
        }

        Console.WriteLine();
    }
}