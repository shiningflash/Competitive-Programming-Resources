"""
BFS

TC: O(V+E)
SC: O(N)
"""


def bfs(graph, start):
    visited, queue = {start}, [start]
    while queue:
        vertex = queue.pop(0)
        print(vertex)
        for node in graph[vertex]:
            if node not in visited:
                queue.append(node)
                visited.add(node)


if __name__ == '__main__':
    graph = {'A': set(['B', 'C']),
             'B': set(['A', 'D', 'E']),
             'C': set(['A', 'F']),
             'D': set(['B']),
             'E': set(['B', 'F']),
             'F': set(['C', 'E'])}
    bfs(graph, 'A')
