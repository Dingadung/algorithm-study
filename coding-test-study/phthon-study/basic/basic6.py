"""
사이즈가 5인 배열에 숫자를 5개 입력받은 후 배열 안에 들어있는 값에 3을 곱해서 다시 그 배열에 넣고 배열 결과 출력
예 )  1 ,2 ,3, 4, 5입력 후 결과 3,6,9,12,15
"""

a = []

a = list(map(int, input().split()))
for i in range(len(a)):
    a[i] = a[i] * 3

for i in range(len(a)):
    print(a[i], " ", end='')
