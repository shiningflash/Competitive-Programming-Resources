using System;
using System.Collections.Generic;

public class DFS {
    
    public int nodes, edges;
    public bool[] vis;
    public List <int>[] graph;

    public DFS() {

    }

    public void initDFS(int nodes, int edges) {
        this.nodes = nodes;
        this.edges = edges;

        graph = new List<int>[nodes];
        vis = new bool[nodes];
        
        for (int i = 0; i < nodes; i++) {
            graph[i] = new List<int>();
        }
    }

    public void dfs(int u) {
        Console.Write("{0} ", u);
        vis[u] = true;

        for (int i = 0; i < graph[u].Count; i++) {
            int v = graph[u][i];
            if (vis[v] == false) {
                dfs(v);
            }
        }
    }

    public void manageDFS(string[] lines) {

        string[] line1 = lines[0].Split(' ');
        int nodes = int.Parse(line1[0]);
        int edges = int.Parse(line1[1]);

        initDFS(nodes, edges);

        for (int i = 1; i <= edges; i++) {
            string[] all_edge = lines[i].Split(' ');
            int u = int.Parse(all_edge[0]);
            int v = int.Parse(all_edge[1]);
            graph[u].Add(v);
            graph[v].Add(u);
        }

        for (int i = 0; i < nodes; i++) {
            if (vis[i] == false) {
                dfs(i);
            }
        } 

        Console.WriteLine();
    }
}