/*
      __Detect Cycle in a Undirected Graph
      __Complexity O(V+E)
                       _
       _|_ o._ o._  __|_| _. _|_
      _>| ||| ||| |(_|| |(_|_>| |
                    _|
*/

using System;
using System.Collections.Generic;

public class CycleDetection {

    public int nodes, edges;
    public List <int>[] graph;

    public CycleDetection() {

    }

    public void initCycleDetection(int nodes, int edges) {
        this.nodes = nodes;
        this.edges = edges;

        graph = new List<int>[nodes];

        for (int i = 0; i < nodes; i++) {
            graph[i] = new List<int>();
        }
    }

    public bool isCyclic_util(int u, int parent, bool[] vis) {

        vis[u] = true;
        
        for (int i = 0; i < graph[u].Count; i++) {
            int v = graph[u][i];

            if (vis[v] == false)  {
                if (isCyclic_util(v, u, vis)) {
                    return true;
                }
            }
            else if (v != parent) {
                return true;
            }
        } 

        return false;
    }

    public bool isCyclic() {
        bool[] visited = new bool[nodes];

        for (int i = 0; i < nodes; i++) {
            visited[i] = false;
        }

        for (int i = 0; i < nodes; i++) {
            if (visited[i] == false) {
                if (isCyclic_util(i, -1, visited)) {
                    return true;
                }
            }
        }

        return false;
    }

    public void manageCycleDetection(string[] lines) {
        string[] line1 = lines[0].Split(' ');
        int nodes = int.Parse(line1[0]);
        int edges = int.Parse(line1[1]);

        initCycleDetection(nodes, edges);

        for (int i = 1; i <= edges; i++) {
            string[] all_edge = lines[i].Split(' ');
            int u = int.Parse(all_edge[0]);
            int v = int.Parse(all_edge[1]);

            graph[u].Add(v);
            graph[v].Add(u);
        }

        if (isCyclic()) {
            Console.WriteLine("Graph contains cycle");
        }
        else {
            Console.WriteLine("Graph doesn't contain cycle");
        }
    }
}

/*
    5 5
    0 1
    0 2
    0 2
    1 2
    3 4
    Graph contains cycle
    
    5 5
    1 0
    0 2
    2 0
    0 3
    3 4
    Graph contains cycle
    
    3 2
    0 1
    1 2
    Graph doesn't contain cycle
*/