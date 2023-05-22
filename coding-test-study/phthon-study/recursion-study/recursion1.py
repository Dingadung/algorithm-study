'''
Sum(3) = 1 + 2 + 3
결과 6
'''


def sum_number(val):
    if val == 0:
        return 0
    else:
        return val + sum_number(val - 1)


print(sum_number(3))
