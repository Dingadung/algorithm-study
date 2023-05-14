class Student:
    def __init__(self, name, school, age, score):
        self.name = name
        self.school = school
        self.age = age
        self.score = score

    def study(self):
        self.score += 20


p1 = Student("John", "high school", 19, 50)

print(p1.name)
print(p1.school)
print(p1.age)

p1.study()
print(p1.score)