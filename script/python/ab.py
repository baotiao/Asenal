#!/usr/bin/env python
import sys

while True:
    line = sys.stdin.readline()
    if int(line) == 42:
        break
    print line
