#!/usr/bin/env python

import urllib2, urllib
request = urllib2.Request('http://localhost:8080/')
request.add_header('host', 'www.chenzongzhi.info')

response = urllib2.urlopen(request)
data = response.read()
print data
