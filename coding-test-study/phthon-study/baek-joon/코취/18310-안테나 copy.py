'''
4
5 1 7 9
'''
import sys
input = sys.stdin.readline
N = int(input()) # 집의 수 N
point = list(map(int, input().split())) # 집에 위치
point.sort()

# point = list(set(point))
# Min = 200001
# ans = 0
# for i in point:
#     S = 0
#     for j in point:
#         S += abs(j-i)
#     if Min > S:
#         Min = S
#         ans = i
# print(point)


print(point[(len(point) - 1)//2])