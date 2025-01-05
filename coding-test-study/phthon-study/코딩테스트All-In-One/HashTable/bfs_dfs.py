from collections import deque
from typing import List


'''
bfs tree
'''
def bfs_tree(root):
    if root is None:
        return None

    visited = []
    q = deque(root)

    while q:
        c_n = q.popleft()
        visited.append(c_n)
        if c_n.left:
            q.append(c_n.left)
        if c_n.right:
            q.append(c_n.right)
    return visited

'''
bfs graph
'''
def bfs_graph(graph, start_vertex):
    visited = [start_vertex]
    q = deque(start_vertex)

    while q:
        current_vertex = q.popleft()
        for v in graph[current_vertex]:
            if v not in visited:
                visited.append(v)
                q.append(v)
    return visited

'''
dfs tree
'''
def dfs_tree(root):
    if root is None:
        return None
    if root.left:
        dfs_tree(root.left)
    if root.right:
        dfs_tree(root.right)

'''
dfs graph
'''
def dfs_graph(graph, current_node, visited):
    visited.append(current_node)

    for vertex in graph[current_node]:
        if vertex not in visited:
            visited.append(vertex)
            dfs_graph(graph, vertex, visited)


'''
question solution
'''
class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        row_number = len(grid)
        col_number = len(grid[0])

        visited = [[False] * col_number for _ in range(row_number)]


        def bfs(x, y):
            dx = [-1, 1, 0, 0]
            dy = [0, 0, -1, 1]
            q = deque()
            q.append((x,y))

            while q:
                xx, yy = q.popleft()
                for i in range(4):
                    for j in range(4):
                        nx = xx + i
                        ny = yy + j
                        if 0 <= nx and nx < row_number and 0 <= col_number:
                            if not visited[nx][ny] and grid[nx][ny] == 1:
                                visited[nx][ny] = True
                                q.append((nx, ny))

            island_count = 0

            for r in range(row_number):
                for c in range(col_number):
                    if not visited[r][c] and grid[r][c] == 1:
                        island_count += 1
                        bfs(r, c)