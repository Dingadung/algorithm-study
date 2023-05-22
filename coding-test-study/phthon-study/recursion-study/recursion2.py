'''
팩토리얼 4 => 1*2*3*4
Fact(4)
결과 24
'''


def factorial(val):
    if val == 1:
        return 1
    else:
        return val * factorial(val - 1)


print(factorial(4))
