'''
문장을 매개변수로 받아 거꾸로 출력하게 해주는 재귀 함수 작성
abcd => dcba
'''


def reverse(str):
    if len(str) == 1:
        return str
    return reverse(str[1:]) + str[0]


print(reverse("abcd"))
