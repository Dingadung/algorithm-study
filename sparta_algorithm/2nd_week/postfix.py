from collections import deque

a = input().split()

q = deque(a)

ans = int(q.popleft())

while q:
    c = int(q.popleft())
    d = q.popleft()
    if d == "+":
        ans += c
    if d == "-":
        ans = ans - c
    if d == "*":
        ans *= c
    if d == "/":
        ans //= c

print(ans)