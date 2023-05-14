class Dog:  # 클래스 선언
    def __init__(self, name, age, breed, weight):
        self.name = name
        self.age = age
        self.breed = breed
        self.weight = weight

    def eat(self, food):
        self.weight += food
        return self.weight

    def bark(self):  # 메소드 선언
        print(self.name + "가 멍멍하고 짖는다.")


