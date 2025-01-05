arr = input()

def find_max_str(arr):
    d = {}
    max_len = 0
    start = 0

    for i in range(len(arr)):
        if arr[i] in d:
            start = i

        d[arr[i]] = i

        max_len = max(max_len, i - start + 1)
    return max_len

print(find_max_str(arr))