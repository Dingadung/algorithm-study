'''
문제
N×M크기의 직사각형이 있다. 각 칸에는 한 자리 숫자가 적혀 있다.
이 직사각형에서 꼭짓점에 쓰여 있는 수가 모두 같은 가장 큰 정사각형을 찾는 프로그램을 작성하시오. 이때, 정사각형은 행 또는 열에 평행해야 한다.

입력
첫째 줄에 N과 M이 주어진다. N과 M은 50보다 작거나 같은 자연수이다. 둘째 줄부터 N개의 줄에 수가 주어진다.

출력
첫째 줄에 정답 정사각형의 크기를 출력한다.

3 5
42101
22100
22101
-> 9
'''

N, M = map(int, input().split())

s =[]
for i in range(N):
    s.append(input())

small = min(N, M)
w = 1

for i in range(N):
    for j in range(M):
        for k in range(1, small):
            if i+k < N and j + k < M:
                if s[i][j] == s[i][j+k] and s[i][j] == s[i+k][j] and s[i][j] == s[i+k][j+k]:
                    w = max(w, (k+1)*(k+1))

print(w)