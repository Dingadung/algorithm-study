'''
피보나치 수열 => 1 1 2 3 5 8 ….
Fibo(5)
결과 5
'''


def fibonacci(val):
    if val <= 2:
        return 1
    return fibonacci(val-1) + fibonacci(val-2)


print(fibonacci(3))
