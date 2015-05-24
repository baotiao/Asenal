#!/usr/bin/env python
import glob
python_file = glob.glob('fibo.py')

print python_file
for fn in sorted(python_file):
    print '   -------', fn
    for line in open(fn):
        print ' ' + line.rstrip()
    print ''
