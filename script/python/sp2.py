#!/usr/bin/env python
import sys
aList = []
MAX = 10000004
def init():
    for i in range(0, MAX + 10):
        aList.append(0)
    for i in range(2, MAX + 1): 
        for j in range(i + i, MAX + 1, i):
            aList[j] = 1
    aList[0] = 1
    aList[1] = 1

def main():
    line = sys.stdin.readline()
    cnt = int(line)
    while True:
        if cnt == 0:
            break
        cnt = cnt -1
        line = sys.stdin.readline()
        nums = str.split(line)
        for i in range(int(nums[0]), int(nums[1])):
            if aList[i] == 0:
                print i

if __name__ == '__main__':
    init()
    main()

