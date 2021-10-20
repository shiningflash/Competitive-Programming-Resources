using System;
using System.Collections.Generic;

public class KruskalMST {

    public struct Edge {
        public int u, v, w;

        public Edge(int u, int v, int w) {
            this.u = u;
            this.v = v;
            this.w = w;
        }
    };

    public int nodes, edges;
    public int[] parent;
    public List <Edge> graph;

    public void initKruskalMST(int nodes, int edges) {
        this.nodes = nodes;
        this.edges = edges;

        parent = new int[nodes];
        graph = new List<Edge>();
    }

    public int find(int r) {
        return (parent[r] == r) ? r : parent[r] = find(parent[r]);
    } 

    public void kruskal_mst() {
        graph.Sort(delegate(Edge e1, Edge e2) {
            return e1.w.CompareTo(e2.w);
        });

        for (int i = 0; i < nodes; i++) {
            parent[i] = i;
        }

        int cnt = 0, total_cost = 0;

        for (int i = 0; i < edges; i++) {
            int u = find(graph[i].u);
            int v = find(graph[i].v);

            if (u != v) {
                Console.WriteLine("( {0} - {1} ) = {2}", graph[i].u, graph[i].v, graph[i].w);

                parent[v] = u;
                total_cost += graph[i].w;

                cnt++;
                if (cnt == nodes - 1) break;
            }
        }

        Console.WriteLine("minimum cost = {0}", total_cost);
    }

    public void manageKruskalMST(string[] lines) {
        
        string[] line1 = lines[0].Split(' ');
        int nodes = int.Parse(line1[0]);
        int edges = int.Parse(line1[1]);

        initKruskalMST(nodes, edges);

        for (int i = 1; i <= edges; i++) {
            string[] all_edge = lines[i].Split(' ');
            int u = int.Parse(all_edge[0]);
            int v = int.Parse(all_edge[1]);
            int w = int.Parse(all_edge[2]);

            graph.Add(new Edge(u, v, w));
        }

        kruskal_mst();
    }
}

/*
 stdin
 - 
4 5
0 1 2
0 2 3
0 3 1
2 1 2
3 2 2
 
 stdout
 -
( 0 : 3 ) = 1
( 0 : 1 ) = 2
( 2 : 1 ) = 2
minimum cost = 5
 */