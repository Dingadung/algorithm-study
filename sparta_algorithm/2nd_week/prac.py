from collections import deque


def isPalindrome(ln):
    arr = []
    head = ln.head

    if not head:
        return True

    node = head
    while node:
        arr.append(node.val)
        node = node.next

    while len(arr) > 1:
        first = arr.pop(0)
        last = arr.pop()
        if first != last:
            return False

    return True


def test_problem_stack(s):
    pair = {
        '}': '{',
        ')': '(',
        ']': '[',
    }
    opener = "({["
    stack = []

    for char in s:
        if char in opener:
            stack.append(char)
        else:
            if not stack:
                return False
            top = stack.pop()
            if pair[char] != top:
                return False

    return not stack


def test_problem_queue(num):
    deq = deque([i for i in range(1, num + 1)])
    while len(deq) > 1:
        deq.popleft()
        deq.append(deq.popleft())
    return deq.popleft()