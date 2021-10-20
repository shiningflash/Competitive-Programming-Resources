using System;
using System.Collections.Generic;

public class SCC {

    public int nodes, edges;
    public List <int>[] graph;
    public List <int>[] revgraph;
    public Stack<int> st;
    public bool[] vis;

    public SCC() {

    }

    public void initSCC(int nodes, int edges) {
        this.nodes = nodes;
        this.edges = edges;

        st = new Stack<int>();
        vis = new bool[nodes];
        graph = new List<int>[nodes];
        revgraph = new List<int>[nodes];

        for (int i = 0; i < nodes; i++) {
            graph[i] = new List<int>();
            revgraph[i] = new List<int>();
        }
    } 

    public void clearVis() {
        for (int i = 0; i < nodes; i++) {
            vis[i] = false;
        }
    }

    public void dfs1(int u) {
        vis[u] = true;

        for (int i = 0; i < revgraph[u].Count; i++) {
            int v = revgraph[u][i];

            if (vis[v] == false) {
                dfs1(v);
            }
        }
        st.Push(u);
    }

    public void dfs2(int u) {
        vis[u] = true;

        Console.Write("{0} ", u);

        for (int i = 0; i < graph[u].Count; i++) {
            int v = graph[u][i];

            if (vis[v] == false) {
                dfs2(v);
            }
        }
    }

    public void manageSCC(string[] lines) {

        string[] line1 = lines[0].Split(' ');
        int nodes = int.Parse(line1[0]);
        int edges = int.Parse(line1[1]);

        initSCC(nodes, edges);

        for (int i = 1; i <= edges; i++) {
            string[] all_edge = lines[i].Split(' ');
            int u = int.Parse(all_edge[0]);
            int v = int.Parse(all_edge[1]);

            graph[u].Add(v);
            revgraph[v].Add(u);
        }

        clearVis();

        for (int i = 0; i < nodes; i++) {
            if (vis[i] == false) {
                dfs1(i);
            }
        }

        clearVis();

        while (st.Count > 0) {
            int u = st.Pop();

            if (vis[u] == false) {
                dfs2(u);
                Console.WriteLine();
            }
        }

    }
}

/*
Input:
-
5 5
1 0
0 2
2 1
0 3
3 4
Output:
-
4 
3 
0 2 1
*/