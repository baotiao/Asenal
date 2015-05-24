#!/usr/bin/env python
import os
import sys 
import urllib

url = "http://www.baidu.com"
ufile = urllib.urlopen(url)
info = ufile.info()
if info.gettype() == 'text/html':
    print 'base url:' + ufile.geturl()
    text = ufile.read()
    print text
