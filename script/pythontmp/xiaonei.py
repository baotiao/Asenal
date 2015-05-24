#!/usr/bin/env python
import urllib,urllib2,re,sys,os,cookielib

cj = cookielib.CookieJar()
opener = urllib2.build_opener(urllib2.HTTPCookieProcessor(cj))
exheaders = [("User-Agent","Mozilla/4.0 (compatible; MSIE 7.1; Windows NT 5.1; SV1)"),]
opener.addheaders=exheaders
url_login = 'http://renren.com/'
body = (('email','czz19891012@126.com'), ('password','tjund4xt'))
req1 = opener.open(url_login, urllib.urlencode(body))
response = urllib2.urlopen('http://renren.com/')
print response.read()
for line in cj:
    print line

#response = urllib2.urlopen('http://chenzongzhi.info/wp-admin/')
#print response.info()
#print response.read()
