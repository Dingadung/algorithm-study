import sys
from collections import deque


def bfs(maze):
    N = len(maze)
    M = len(maze[0]) if N > 0 else 0

    # 이동 방향 (상, 하, 좌, 우)
    directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]

    queue = deque([(0, 0, 1)])  # (x, y, 경로 길이)
    visited = set((0, 0))  # 방문한 위치 저장

    while queue:
        x, y, length = queue.popleft()

        # 출구에 도달한 경우
        if x == N - 1 and y == M - 1:
            return length

        # 상하좌우 탐색
        for dx, dy in directions:
            nx, ny = x + dx, y + dy

            # 범위 체크 및 벽이 아닌 경우
            if 0 <= nx < N and 0 <= ny < M and (nx, ny) not in visited and maze[nx][ny] == '1':
                visited.add((nx, ny))
                queue.append((nx, ny, length + 1))

    return -1  # 출구에 도달할 수 없는 경우

N, M = map(int, (input().split()))

maze_input = []
for i in range(N):
    maze_input.append(list(input()))

print(bfs(maze_input))
