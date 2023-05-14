"""
1부터 10까지 숫자중에 짝수만 더한 결과 출력
"""

S=0
for i in range(1, 11) :
   if i%2==0:
        S += i

print(S)
