#!/usr/bin/env python

import smtplib
import string
import poplib
import sys,os
import StringIO,rfc822

host = 'smtp.qq.com'
f_address = '251250980@qq.com'
t_address = ["bingying427@sina.com"]
msg = "Subject:Hi from Python\n"
s = smtplib.SMTP(host)
s.set_debuglevel(True)
s.login(f_address, 'waiwaishu')
error = s.sendmail(f_address, t_address, msg)
print 'here'


