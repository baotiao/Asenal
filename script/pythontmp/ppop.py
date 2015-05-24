#!/usr/bin/env python

import string
import poplib
import sys,os
import StringIO,rfc822

servername = 'pop.qq.com'
username = '251250980@qq.com'
passwd = 'waiwaishu'
#print 'up'
pop = poplib.POP3(servername)

#pop.set_debuglevel(1)
pop.user(username)
pop.pass_(passwd)
num, ret = pop.stat()
print num, ret

hdr, text, octet = pop.retr(1)
print hdr
print octet
text = string.join(text, "\n")
#print text
file = StringIO.StringIO(text)
message = rfc822.Message(file)
for k, v in message.items():
    print k
print message.fp.read()
sys.exit(0)
#print ret
for i in range(1, ret[0] + 1):
    mlist = pop.top(i, 0)
    #print 'line: ', len(mlist[1])
ret = pop.list()
print ret
down = pop.retr(1)
print 'line:', len(down)
