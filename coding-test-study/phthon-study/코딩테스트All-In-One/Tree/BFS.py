from collections import deque


def bfs(root):
    visited = []
    if root is None:
        return
    q = deque()
    q.append(root)
    while q:
        current_node = q.popleft() # 접근
        visited.append(current_node.value)

        if current_node.left:
            q.append(current_node.left)
        if current_node.right:
            q.append(current_node.right)
    return visited

bfs(root)
