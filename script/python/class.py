#!/usr/bin/env python
class BankAccount(object):
    def __init__(self, initial_balance = 0):
        self.amount = initial_balance
    def deposit(self, amount):
        self.amount += amount
    def withdraw(self, amount):
        self.amount -= amount
    def overdrawn(self):
        return self.balance < 0
my_account = BankAccount(15)
my_account.withdraw(5)
print my_account.amount
