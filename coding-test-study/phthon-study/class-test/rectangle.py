class Rectangle:
    def __init__(self, side, angle, base, height):
        self.side = side
        self.angle = angle
        self.base = base
        self.height = height

    def cal_width(self):
        return self.base*self.height

p1 = Rectangle(4, 4, 10, 11)

print(p1.side)
print(p1.angle)
print(p1.base)
print(p1.height)
print("width = ", p1.cal_width())