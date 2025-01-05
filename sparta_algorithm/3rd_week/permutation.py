def backtrack(path, nums, used, result):
    if len(path) == len(nums):
        result.append(path[:])  # 현재 경로를 결과에 추가
        return

    for i in range(len(nums)):
        if used[i]:
            continue  # 이미 사용된 숫자는 무시

        # 현재 숫자 사용
        used[i] = True
        path.append(nums[i])

        # 다음 숫자 선택
        backtrack(path, nums, used, result)

        # 백트래킹: 현재 숫자 제거
        path.pop()
        used[i] = False

def permute(nums):
    result = []
    used = [False] * len(nums)  # 숫자 사용 여부를 추적
    backtrack([], nums, used, result)
    return result

nums = list(map(int, input().split(',')))
print(permute(nums))