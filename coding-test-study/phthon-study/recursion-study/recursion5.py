'''
정수를 매개변수 n으로 받아서 1이상 n이하 숫자 중 짝수 합을 리턴하는 재귀 함수 작성

Func(5)
결과  6.
'''


def Func(n):
    if n == 1:
        return 0
    if n % 2 == 0:
        return n + Func(n - 1)
    else:
        return Func(n - 1)


n = int(input())
print(Func(n))
