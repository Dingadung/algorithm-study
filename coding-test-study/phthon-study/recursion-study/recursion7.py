'''
Write a static recursive method evenFactors that takes as input two positive integers and
prints the even factors of the first integer that are greater than or equal to the second
integer. For example, evenFactors(18,1) prints 2, 6, and 18, since the even factors of 18
that are greater than or equal to 1 are 2,6, and 18.
'''


def Func(a, b):
    if a < b:
        return 0
    if a % b == 0 and b % 2 == 0:
        print(b)
    return Func(a, b+1)



Func(18, 1)
