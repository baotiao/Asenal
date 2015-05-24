#!/usr/bin/env python
import sys
def fun(num):
    if num == 0:
        return 0
    return num / 5 + fun(num / 5)

line = sys.stdin.readline()
num = int(line)
while True:
    if num == 0:
        break
    num = num -1
    n = int(sys.stdin.readline())
    print fun(n)
