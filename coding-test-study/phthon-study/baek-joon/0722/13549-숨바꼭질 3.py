'''
문제
수빈이는 동생과 숨바꼭질을 하고 있다. 수빈이는 현재 점 N(0 ≤ N ≤ 100,000)에 있고, 동생은 점 K(0 ≤ K ≤ 100,000)에 있다.
수빈이는 걷거나 순간이동을 할 수 있다. 만약, 수빈이의 위치가 X일 때 걷는다면 1초 후에 X-1 또는 X+1로 이동하게 된다.
순간이동을 하는 경우에는 0초 후에 2*X의 위치로 이동하게 된다.

수빈이와 동생의 위치가 주어졌을 때, 수빈이가 동생을 찾을 수 있는 가장 빠른 시간이 몇 초 후인지 구하는 프로그램을 작성하시오.

입력
첫 번째 줄에 수빈이가 있는 위치 N과 동생이 있는 위치 K가 주어진다. N과 K는 정수이다.

출력
수빈이가 동생을 찾는 가장 빠른 시간을 출력한다.

5 17 -> 2
'''
from collections import deque
N, K = map(int, input().split())

visited = [False]*100001
q = deque()
dx = [-1, 1]

visited[N] = True
q.append(N)
time = 0
while len(q) !=0:
    curr = q.popleft()
    if curr == K:
        break
    print(curr)
    if curr*2 and curr*2 < 100001:
        if visited[curr*2] == False:
            visited[curr*2] = True
            q.append(curr*2)
    for i in range(2):
        next_x = dx[i] + curr
        if visited[next_x] and visited[next_x] < 100001:
            if visited[next_x] == False:
                visited[next_x] = True
                q.append(next_x)
                time += 1

print(time)