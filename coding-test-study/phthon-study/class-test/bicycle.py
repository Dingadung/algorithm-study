class Bicycle:
    def __init__(self, left_distance, right_distance, straight_distance, speed, status):
        self.left_distance = left_distance
        self.right_distance = right_distance
        self.straight_distance = straight_distance
        self.speed = speed
        self.status = status

    def accel(self, state, time):
        self.speed += 1
        self.status = 'running'
        if state == 'left':
            self.left_distance += self.speed * time
        elif state == 'right':
            self.right_distance += self.speed * time
        elif state == 'straight':
            self.straight_distance += self.speed * time

    def brake_action(self, state, time):
        if self.speed - 1 < 0:
            self.status = 'stop'
            return
        self.speed -= 1
        if self.speed == 0:
            self.status = 'stop'
            return
        if state == 'left':
            self.left_distance -= self.speed * time
        elif state == 'right':
            self.right_distance -= self.speed * time
        elif state == 'straight':
            self.straight_distance -= self.speed * time

    def print_status(self):
        print('status = ', self.status, 'speed = ', self.speed, self.right_distance,
              self.left_distance, self.straight_distance)


p1 = Bicycle(0, 0, 0, 0, 'stop')
p1.accel('straight', 100)
p1.accel('left', 200)
p1.accel('right', 300)
p1.print_status()

p1.brake_action('straight', 400)
p1.brake_action('left', 30)
p1.brake_action('right', 20)

p1.print_status()

