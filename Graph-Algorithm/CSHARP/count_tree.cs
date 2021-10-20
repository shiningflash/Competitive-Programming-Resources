using System;
using System.Collections.Generic;

public class CountTree {

    public int nodes, edges;
    public List <int>[] graph;
    public bool[] vis;

    public CountTree() {

    }

    public void initCountTree(int nodes, int edges) {
        this.nodes = nodes;
        this.edges = edges;

        vis = new bool[nodes];
        graph = new List<int>[nodes];

        for (int i = 0; i < nodes; i++) {
            graph[i] = new List<int>();
        }
    }

    public void dfs(int u) {
        vis[u] = true;

        for (int i = 0; i < graph[u].Count; i++) {
            int v = graph[u][i];

            if (vis[v] == false) {
                dfs(v);
            }
        }
    }

    public int getTotalTree() {
        for (int i = 0; i < nodes; i++) {
            vis[i] = false;
        }

        int cnt = 0;

        for (int i = 0; i < nodes; i++) {
            if (vis[i] == false) {
                dfs(i);
                cnt++;
            }
        }

        return cnt;
    }

    public void manageCountTree(string[] lines) {
        string[] line1 = lines[0].Split(' ');
        int nodes = int.Parse(line1[0]);
        int edges = int.Parse(line1[1]);

        initCountTree(nodes, edges);

        for (int i = 1; i <= edges; i++) {
            string[] all_edge = lines[i].Split(' ');
            int u = int.Parse(all_edge[0]);
            int v = int.Parse(all_edge[1]);

            graph[u].Add(v);
            graph[v].Add(u);
        }

        int total_tree = getTotalTree();
        Console.WriteLine("Number of trees = {0}", total_tree);
    }
}

/*
 INPUT
 -
   - first line, n = 5 Vertex, m = 3 Edge
5 3
0 1
0 2
3 4

OUTPUT
 -
 Number of trees = 2
 */