from collections import deque
from typing import List


'''
bfs tree
'''
def bfs(root):
    if root is None:
        return None
    visited = []
    q = deque()
    q.append(root)

    while q:
        current_node = q.popleft()
        visited.append(current_node)

        if current_node.left:
            q.append(current_node.left)
        if current_node.right:
            q.append(current_node.right)
    return visited

'''
bfs graph
'''
def bfs(graph, start_vertex):
    visited = [start_vertex]
    q = deque(start_vertex)

    while q:
        current_vertex = q.popleft()
        for vertex in graph[current_vertex]:
            if vertex not in visited:
                visited.append(vertex)
                q.append(vertex)
    return visited

'''
dfs tree
'''
def dfs(current_node):
    if current_node is None:
        return None
    if current_node.left:
        dfs(current_node.left)
    if current_node.right:
        dfs(current_node.right)

'''
dfs graph
'''
def dfs(graph, current_node, visited = []):
    visited.append(current_node)

    for vertex in graph[current_node]:
        if vertex not in visited:
            dfs(graph, vertex, visited)



class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        row_number = len(grid)
        col_number = len(grid[0])
        visited = [[False] * col_number for _ in range(row_number)]

        island_count = 0

        def bfs(x, y):
            dx = [-1, 1, 0, 0]  # 대각선은 +1 +1
            dy = [0, 0, -1, 1]  # 대각선은 +1 +1

            visited[x][y] = True
            q = deque([(x, y)])

            while q:
                curr_x, curr_y = q.popleft()
                for i in range(4):
                    new_x = curr_x + dx[i]
                    new_y = curr_y + dy[i]
                    if new_x >= 0 and new_x < row_number and new_y >= 0 and new_y < col_number:
                        if grid[new_x][new_y] != "0" and visited[new_x][new_y] is not True:  # 방문하면 안되는 애들
                            visited[new_x][new_y] = True
                            q.append((new_x, new_y))

        for i in range(row_number):
            for j in range(col_number):
                if grid[i][j] == "1" and not visited[i][j]:
                    # 땅이면서 방문하지 않았을 때
                    island_count += 1
                    bfs(i, j)
        return island_count
