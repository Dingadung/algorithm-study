def checkPalindrome(a):
    for i in range(len(a)//2):
        if a[i] == a[len(a)-1-i]:
            return True
    return False

a = input()

print(checkPalindrome(a))

