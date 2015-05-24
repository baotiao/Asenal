#!/usr/bin/env python

import urllib2
import urllib

response = urllib2.urlopen('http://www.baidu.com:80/')
print 'RESPONSE', response
print 'URL "', response.geturl()

headers = response.info()
print 'DATE: ', headers['date']
print headers

data = response.read()
#print data

query_args = {'q':'query string', 'foo':'bar'}
encoded_args = urllib.urlencode(query_args)
print 'Encode:', encoded_args
url = 'http://www.baidu.com/?'
print urllib2.urlopen(url).read()
