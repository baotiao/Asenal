#!/usr/bin/env python

import urllib2
import Cookie
response = urllib2.urlopen('http://www.baidu.com/')
header = response.info()
print header
content = response.read()
#print content

c = Cookie.SimpleCookie()
c['mycookie'] = 'cookie_value'
print c

