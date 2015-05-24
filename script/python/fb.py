#!/usr/bin/env python
f = open('a', 'r')
l = f.readlines()
num = l[0]
for i in range(1, int(num) + 1):
    if i % 3 == 0 and i % 5 == 0:
        print 'Hop'
    elif i % 3 == 0:
        print 'Hoppity'
    elif i % 5 == 0:
        print 'Hophop'

