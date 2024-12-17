'''
bfs tree
'''
from collections import deque
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
def dfs(graph, current_vertex, visited = []):
    visited.append(current_vertex)

    for v in graph[current_vertex]:
        if v not in visited:
            dfs(graph, v, visited)


'''
solution
'''
