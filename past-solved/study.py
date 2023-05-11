# prime_list는 1부터 10000사이의 소수가 오름차순으로 저장된 리스트예요.
from prime import prime_list

# 합계가 짝수가 되는 두 소수를 찾는 함수예요.
def goldbach(arr):
    # 합계가 짝수가 되는 두 소수를 작은 수부터 차례로 리스트에 저장해 주세요.
    ans = []
    for i in range(len(arr)):
        mid1 = (arr[i])//2
        mid2 = (arr[i])//2

        if prime_list[mid1] + prime_list[mid2] == i :
            ans.append([prime_list[mid1], prime_list[mid2]])
            print(ans)
    
    return ans


arr = [int(x) for x in input().split()]

for i in goldbach(arr):
    print(i[0], i[1])