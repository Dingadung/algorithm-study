'''
문제
월드컵 축구의 응원을 위한 모임에서 회장을 선출하려고 한다.
이 모임은 만들어진지 얼마 되지 않았기 때문에 회원 사이에 서로 모르는 사람도 있지만, 몇 사람을 통하면 모두가 서로 알 수 있다.
각 회원은 다른 회원들과 가까운 정도에 따라 점수를 받게 된다.

예를 들어 어느 회원이 다른 모든 회원과 친구이면, 이 회원의 점수는 1점이다.
어느 회원의 점수가 2점이면, 다른 모든 회원이 친구이거나 친구의 친구임을 말한다.
또한 어느 회원의 점수가 3점이면, 다른 모든 회원이 친구이거나, 친구의 친구이거나, 친구의 친구의 친구임을 말한다.

4점, 5점 등은 같은 방법으로 정해진다.
각 회원의 점수를 정할 때 주의할 점은 어떤 두 회원이 친구사이이면서 동시에 친구의 친구사이이면, 이 두사람은 친구사이라고 본다.

회장은 회원들 중에서 점수가 가장 작은 사람이 된다. 회장의 점수와 회장이 될 수 있는 모든 사람을 찾는 프로그램을 작성하시오.

입력
입력의 첫째 줄에는 회원의 수가 있다. 단, 회원의 수는 50명을 넘지 않는다.
둘째 줄 이후로는 한 줄에 두 개의 회원번호가 있는데, 이것은 두 회원이 서로 친구임을 나타낸다.
회원번호는 1부터 회원의 수만큼 붙어 있다. 마지막 줄에는 -1이 두 개 들어있다.

출력
첫째 줄에는 회장 후보의 점수와 후보의 수를 출력하고, 두 번째 줄에는 회장 후보를 오름차순으로 모두 출력한다.
1: 2
2: 3 4
3: 4
4: 5
5: 3

5
1 2
2 3
3 4
4 5
2 4
5 3
-1 -1
->
2 3
2 3 4
'''
N = int(input()) # 회원의 수
visited = [False]*(N+1)
con = [[] for i in range(N+1)]
while True:
    a1, a2 = map(int, input().split())
    if a1 == -1 and a2 == -1:
        break
    con[a1].append(a2)
    con[a2].append(a1)
# print("con = ", con)

cnt = {}
MIN = 51
for i in range(1, N+1):
    cnt[i] = N - len(con[i])

for i in range(1, N+1):
    if MIN >= cnt[i]:
        MIN = cnt[i]

ans = []
for i in range(1, N+1):
    if MIN == cnt[i]:
        ans.append(i)
print(MIN, len(ans))
print(*ans)
'''
1: 2
2: 3 4
3: 4
4: 5
5: 3

1: 2
2: 1 3 4
3: 2 4 5
4: 2 3 5
5: 3 4
'''
# for i in range(1, N+1):
#     visited[i] = True
#     stack = []
#     stack.append(i)
#     while len(stack) != 0:
#         s = stack.pop()
#         for next in con[s]:
#             if visited[s] == False:
#                 visited[s] = True
#                 stack.append(next)
#         if cnt[s] == 0:
#             cnt[s] = 1
#         print("cnt[%d] = %d" %(s, cnt[s]))