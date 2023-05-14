class Account:

    def __init__(self, name, money, number, bank_name, log):
        self.name = name
        self.money = money
        self.number = number
        self.bank_name = bank_name
        self.log = log

    def transfer(self, send, sendTo):
        if self.money - send <= 0:
            state = {"state": "transfer_fail", "money": self.money, "sendTo": sendTo}
            self.log.append(state)
            return

        self.money -= send
        sendTo.money += send
        state = {"state": "transfer", "money": self.money, "sendTo": sendTo.name}
        state2 = {"state": "deposit", "money": sendTo.money, "sendBy" : self.name}

        self.log.append(state)
        sendTo.log.append(state2)

        return self.log

    def withdraw(self, send):
        if self.money - send <= 0:
            state = {"state": "withdraw_fail", "money": self.money}
            self.log.append(state)
            return

        self.money -= send
        state = {"state": "withdraw", "money": self.money}
        self.log.append(state)
        return self.log

    def deposit(self, inputMoney):
        self.money += inputMoney
        state = {"state": "deposit", "money": self.money}
        self.log.append(state)
        return self.log

    def get_log(self):
        return self.log


p1 = Account("John", 10000, 111111, "abc", [])
p2 = Account("Sam", 20000, 222222, "qwe", [])

p1.withdraw(2000)

p2.deposit(30000)

p1.transfer(2000, p2)
print('p1 money = ', p1.money)
print('p1 log = ', p1.get_log())
print('p2 money = ', p2.money)
print('p2 log = ', p2.get_log())

p1.withdraw(30000)
print('p1 log = ', p1.get_log())
