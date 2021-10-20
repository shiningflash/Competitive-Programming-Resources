using System;
using System.Collections.Generic;

public class Dijkstra {

    public struct Node {
        public int v, w;

        public Node(int v, int w) {
            this.v = v;
            this.w = w;
        }
    };

    public int nodes, edges;
    public List <Node>[] graph;
    public int[] dis;

    public Dijkstra() {

    }

    public void initDijkstra(int nodes, int edges) {
        this.nodes = nodes;
        this.edges = edges;

        dis = new int[nodes+1];
        graph = new List<Node>[nodes+1];

        for (int i = 1; i <= nodes; i++) {
            graph[i] = new List<Node>();
        }
    }

    public void dijkstra(int source) {
        for (int i = 1; i <= nodes; i++) {
            dis[i] = int.MaxValue;
        }

        PriorityQueue<int> pq = new PriorityQueue<int>();

        pq.Add(source, 0);
        dis[source] = 0;

        while (pq.Count() > 0) {
            int u = pq.RemoveMin();

            for (int j = 0; j < graph[u].Count; j++) {
                int v = graph[u][j].v;
                int w = graph[u][j].w;

                if (dis[u] + w < dis[v]) {
                    dis[v] = dis[u] + w;
                    pq.Add(v, dis[v]);
                }
            }
        }
    }

    public void print_distance(int source) {
        Console.WriteLine("u - v = w\n---------");
        for (int i = 1; i <= nodes; i++) {
            Console.WriteLine("{0} - {1} = {2}", source, i, dis[i]);
        }
    }

    public void manageDijkstra(string[] lines) {
        string[] line1 = lines[0].Split(' ');
        int nodes = int.Parse(line1[0]);
        int edges = int.Parse(line1[1]);

        initDijkstra(nodes, edges);

        for (int i = 1; i <= edges; i++) {
            string[] all_edge = lines[i].Split(' ');
            int u = int.Parse(all_edge[0]);
            int v = int.Parse(all_edge[1]);
            int w = int.Parse(all_edge[2]);

            graph[u].Add(new Node(v, w));
            graph[v].Add(new Node(u, w));
        }

        int source = int.Parse(lines[edges+1]);

        dijkstra(source);

        print_distance(source);
    }
}

/*
Input
-
5 7
1 4 35
1 2 40
1 5 5
5 3 10
1 3 25
3 2 10
2 4 2
1

Output
-
u - v = w
---------
1 - 1 = 0
1 - 2 = 25
1 - 3 = 15
1 - 4 = 27
1 - 5 = 5
*/