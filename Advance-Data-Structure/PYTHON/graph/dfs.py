"""
DFS

TC: O(V+E)
SC: O(V)
"""


def dfs(graph, visited, node):
    if node in visited:
        return

    print(node)
    visited.add(node)
    for neighbour in graph[node]:
        dfs(graph, visited, neighbour)


if __name__ == '__main__':
    graph = {
        '5': ['3', '7'],
        '3': ['2', '4'],
        '7': ['8'],
        '2': [],
        '4': ['8'],
        '8': []
    }
    visited = set()
    dfs(graph, visited, '5')
