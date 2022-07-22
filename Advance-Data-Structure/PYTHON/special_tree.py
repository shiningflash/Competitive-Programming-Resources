import collections


def findRoot(parents, hasParent):
    for parent in parents:
        if parent not in hasParent:
            return parent


def dfs(graph, level, node):
    for _ in range(level):
        print('\t', end='')
    print(node)

    for child in graph[node]:
        dfs(graph, level+1, child)


if __name__ == '__main__':
    relations = [
        ["animal", "mammal"],
        ["animal", "bird"],
        ["lifeform", "animal"],
        ["cat", "lion"],
        ["mammal", "cat"],
        ["animal", "fish"]
    ]
    graph = collections.defaultdict(list)
    hasParent = dict()
    parents = set()
    for u, v in relations:
        graph[u].append(v)
        parents.add(u)
        hasParent[v] = True
    root = findRoot(parents, hasParent)
    dfs(graph, 0, root)


"""
OUTPUT
-
lifeform
        animal
                mammal
                        cat
                                lion
                bird
                fish
"""
