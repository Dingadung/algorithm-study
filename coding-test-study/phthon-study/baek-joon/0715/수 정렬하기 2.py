'''
N개의 수가 주어졌을 때, 이를 오름차순으로 정렬하는 프로그램을 작성하시오.

첫째 줄에 수의 개수 N(1 ≤ N ≤ 1,000,000)이 주어진다. 둘째 줄부터 N개의 줄에는 수가 주어진다.
이 수는 절댓값이 1,000,000보다 작거나 같은 정수이다. 수는 중복되지 않는다.

5
5
4
3
2
1
-> 1
2
3
4
5
'''
import sys
N = int(sys.stdin.readline())
a = []
for i in range(N):
    num = int(sys.stdin.readline())
    a.append(num)

a.sort()
for i in range(N):
    print(a[i])