def is_in_cycle(node, parent=None):
    # Run depth first search on a given node to see if it is part of any cycle
    # parent is the parent of the current node in the DFS and should be ignored as a neighbour
    i, j = node
    visited[i][j] = True

    for neighbor in neighbors[i][j]:
        x, y = neighbor
        if neighbor!=parent and (visited[x][y] or is_in_cycle(neighbor, node)):
            return True
    return False

def has_cycle():
    for i in range(n):
        for j in range(m):
            if visited[i][j]:
                continue
            if is_in_cycle((i, j)):
                return True
    return False

n, m = map(int, input().split())

board = []
for i in range(n):
    board.append(list(input()))

# Build adjacency lists
neighbors = [[[] for _ in range(m)] for _ in range(n)]
for i in range(n):
    for j in range(m):
        c = board[i][j]
        if i>0 and board[i-1][j]==c:
            neighbors[i][j].append((i-1, j))
        if j>0 and board[i][j-1]==c:
            neighbors[i][j].append((i, j-1))
        if i<n-1 and board[i+1][j]==c:
            neighbors[i][j].append((i+1, j))
        if j<m-1 and board[i][j+1]==c:
            neighbors[i][j].append((i, j+1))

# Find cycles
visited = [[False for _ in range(m)] for _ in range(n)]
print("Yes" if has_cycle() else "No")