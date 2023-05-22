'''
문자열과 문자 2개를 매개변수 str1과 char1으로 받아서 str1에 char1이 몇 개 들어있는지 개수를 세어주는 재귀 함수 작성

Func( “AbCdd”, ‘d’ )
결과  2.
'''


def Func(str1, char1):
    if len(str1) == 0:
        return 0
    if char1 == str1[0]:
        return 1 + Func(str1[1:], char1)
    else:
        return Func(str1[1:], char1)


print(Func('AbCdd', 'd'))
