#!/usr/bin/env python
import os
import sys
import commands

cmd = 'ls -l ./'
print "command to run:", cmd
(status, output) = commands.getstatusoutput(cmd)
print output
print status

paths = os.listdir('./')
for fname in paths:
    print fname
