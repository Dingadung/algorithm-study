'''
빙고 게임은 다음과 같은 방식으로 이루어진다.

먼저 아래와 같이 25개의 칸으로 이루어진 빙고판에 1부터 25까지 자연수를 한 칸에 하나씩 쓴다

다음은 사회자가 부르는 수를 차례로 지워나간다. 예를 들어 5, 10, 7이 불렸다면 이 세 수를 지운 뒤 빙고판의 모습은 다음과 같다.

차례로 수를 지워가다가 같은 가로줄, 세로줄 또는 대각선 위에 있는 5개의 모든 수가 지워지는 경우 그 줄에 선을 긋는다.

이러한 선이 세 개 이상 그어지는 순간 "빙고"라고 외치는데, 가장 먼저 외치는 사람이 게임의 승자가 된다.

철수는 친구들과 빙고 게임을 하고 있다. 철수가 빙고판에 쓴 수들과 사회자가 부르는 수의 순서가 주어질 때, 사회자가 몇 번째 수를 부른 후 철수가 "빙고"를 외치게 되는지를 출력하는 프로그램을 작성하시오.

입력
첫째 줄부터 다섯째 줄까지 빙고판에 쓰여진 수가 가장 위 가로줄부터 차례대로 한 줄에 다섯 개씩 빈 칸을 사이에 두고 주어진다.
여섯째 줄부터 열째 줄까지 사회자가 부르는 수가 차례대로 한 줄에 다섯 개씩 빈 칸을 사이에 두고 주어진다.
빙고판에 쓰여진 수와 사회자가 부르는 수는 각각 1부터 25까지의 수가 한 번씩 사용된다.

출력
첫째 줄에 사회자가 몇 번째 수를 부른 후 철수가 "빙고"를 외치게 되는지 출력한다.

11 12 2 24 10
16 1 13 3 25
6 20 5 21 17
19 4 8 14 9
22 15 7 23 18
5 10 7 16 2
4 22 8 17 13
3 18 1 6 25
12 19 23 14 21
11 24 9 20 15 -> 15

9 10 1 11 12
13 14 2 15 16
3 4 17 5 6
18 19 7 20 21
22 23 8 24 25
1 2 3 4 5
6 7 8 9 10
11 12 13 14 15
16 17 18 19 20
21 22 23 24 25 -> 17
'''
dict = {}
bingo = []
for i in range(5):
    bingo.append(list(map(int, input().split())))

for i in range(5):
    for j in range(5):
        dict[bingo[i][j]] = False
c = []
for i in range(5):
    c.append(list(map(int, input().split())))

def check_bingo():
    cnt = 0
    for i in range(5):
        if dict[bingo[i][0]] and dict[bingo[i][1]] and dict[bingo[i][2]] and dict[bingo[i][3]] and dict[bingo[i][4]]:
            cnt += 1
    for j in range(5):
        if dict[bingo[0][j]] and dict[bingo[1][j]] and dict[bingo[2][j]] and dict[bingo[3][j]] and dict[bingo[4][j]]:
            cnt += 1
    if (dict[bingo[0][0]] and dict[bingo[1][1]] and dict[bingo[2][2]] and dict[bingo[3][3]] and dict[bingo[4][4]]) :
        cnt += 1
    if (dict[bingo[0][4]] and dict[bingo[1][3]] and dict[bingo[2][2]] and dict[bingo[3][1]] and dict[bingo[4][0]]):
        cnt += 1
    if cnt >= 3:
        return True
    return False

def check():
    n = 0
    for i in range(5):
        for j in range(5):
            n += 1
            if c[i][j] in dict:
                dict[c[i][j]] = True
                if check_bingo():
                    return (n)

print(check())