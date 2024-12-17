def bfs(graph, start_vertex):
    visited = [start_vertex]
    q = deque(start_vertex)

    while q:
        current_vertex = q.popleft()
        for v in graph[current_vertex]:
            if v not in visited:
                visited.append(v)
                q.append(v)
    return visited

def dfs(graph, current_vertex, visited = []):
    visited.append(current_vertex)
    for v in graph[current_vertex]:
        if v not in visited:
            visited = dfs(graph, v, visited)
    