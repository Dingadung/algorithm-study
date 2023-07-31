'''
문제
방향 없는 그래프가 주어졌을 때, 연결 요소 (Connected Component)의 개수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 정점의 개수 N과 간선의 개수 M이 주어진다. (1 ≤ N ≤ 1,000, 0 ≤ M ≤ N×(N-1)/2)
둘째 줄부터 M개의 줄에 간선의 양 끝점 u와 v가 주어진다. (1 ≤ u, v ≤ N, u ≠ v) 같은 간선은 한 번만 주어진다.

출력
첫째 줄에 연결 요소의 개수를 출력한다.
6 5
1 2
2 5
5 1
3 4
4 6 -> 2
'''
import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**6)
def dfs(start, depth):
    visited[start] = True
    for i in con[start]:
        if visited[i] == False:
            dfs(i, depth+1)

N, M = map(int, input().split())

visited = [False]*(N+1)
con = [[] for i in range(N+1)]

for _ in range(M):
    u, v = map(int, input().split())
    con[u].append(v)
    con[v].append(u)

cnt = 0
for i in range(1, N+1):
    if visited[i] == False:
        if not con[i]:
            cnt += 1
            visited[i] = True
        else:
            dfs(i, 0)
            cnt += 1

print(cnt)