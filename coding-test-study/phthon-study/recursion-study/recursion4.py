'''
문장을 매개변수로 받아 거꾸로 출력하게 해주는 재귀 함수 작성
abcd => dcba
'''


def reverse(str):
    if len(str) == 0:
        return str
    length = len(str)-1
    print(str[length], end='')

    return reverse(str[:length])


reverse("abcd")
