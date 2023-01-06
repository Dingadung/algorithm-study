# 숫자 맞추기 게임
import random

random_num = random.randint(1, 100)

while(True):
    try:
        try_number = int(input())
        if try_number > random_num:
            print("down")
        elif try_number < random_num:
            print("up")
        else:
            print("answer!")
            break
    except:
        print("올바른 값(정수)을 입력하시오!")

