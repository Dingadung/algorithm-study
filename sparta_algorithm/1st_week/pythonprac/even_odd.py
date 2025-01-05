a = int(input())

def checkIsEven(a):
    if a % 2 == 0:
        return "짝수입니다."
    else:
        return "홀수입니다."

print(checkIsEven(a))