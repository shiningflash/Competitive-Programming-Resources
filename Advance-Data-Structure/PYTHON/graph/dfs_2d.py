"""
DFS

TC: O(V*E)
SC: O(V*E)
"""


dx = [0, 1, 0, -1]
dy = [-1, 0, 1, 0]


def isInside(row, column, ROW, COLUMN):
    return row >= 0 and column >= 0 \
            and row < ROW and column < COLUMN


def isVisited(row, column, visited):
    return visited[row][column]


def isValid(row, column, ROW, COLUMN, visited):
    return isInside(row, column, ROW, COLUMN) and \
            not isVisited(row, column, visited)


def dfs_2d(grid, ROW, COLUMN, visited, row, column):
    queue = [(row, column)]

    while queue:
        top = queue.pop()
        # print(top, top[0], top[1], '===')
        x = top[0]
        y = top[1]

        if not isValid(x, y, ROW, COLUMN, visited):
            continue

        visited[x][y] = True
        print(grid[x][y], end=" ^^^\n")

        for i in range(4):
            nx = x + dx[i]
            ny = x + dy[i]
            queue.append((nx, ny))


if __name__ == '__main__':
    grid = [[1, 2, 3, 4],
            [5, 6, 7, 8],
            [9, 10, 11, 12],
            [13, 14, 15, 16]]
    ROW = len(grid)
    COLUMN = len(grid[0])
    visited = [[False for i in range(COLUMN)] for j in range(ROW)]
    dfs_2d(grid, ROW, COLUMN, visited, 0, 0)
