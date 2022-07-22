from collections import deque

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


def bfs_2d(grid, ROW, COLUMN, visited, row, column):
    queue = deque()
    queue.append((row, column))
    visited[row][column] = True

    while queue:
        front = queue.popleft()
        x = front[0]
        y = front[1]
        print(grid[x][y], end=' ')

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if isValid(nx, ny, ROW, COLUMN, visited):
                queue.append((nx, ny))
                visited[nx][ny] = True


if __name__ == '__main__':
    grid = [[1, 2, 3, 4],
            [5, 6, 7, 8],
            [9, 10, 11, 12],
            [13, 14, 15, 16]]
    ROW = len(grid)
    COLUMN = len(grid[0])
    visited = [[False for i in range(COLUMN)] for j in range(ROW)]
    bfs_2d(grid, ROW, COLUMN, visited, 0, 0)
