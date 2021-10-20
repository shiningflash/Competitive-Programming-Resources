def read_file(file_name):
    try:
        with open(file_name) as fh:
            maze = [[char for char in line.strip("\n")] for line in fh]
            num_cols = len(maze[0])
            for row in maze:
                if len(row) != num_cols:
                    print("The maze is not rectangular")
                    raise SystemExit
            return maze
    except OSError:
        print("There is a problem")
        raise SystemExit
    
if __name__ == '__main__' :
    maze = read_file("PYTHON/files/maze.txt")
    for row in maze:
        print(row)