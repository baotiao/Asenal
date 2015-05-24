#!/usr/bin/env python
import urllib,urllib2,re,sys,os,cookielib

cj = cookielib.CookieJar()
opener = urllib2.build_opener(urllib2.HTTPCookieProcessor(cj))
exheaders = [("User-Agent","Mozilla/4.0 (compatible; MSIE 7.1; Windows NT 5.1; SV1)"),]
opener.addheaders=exheaders
url_login = 'https://cs.login.cmu.edu/idp/Authn/Stateless'
url_cmu = 'https://cs.login.cmu.edu'
body = (('email','baotiao@gmail.com'), ('password','chenzongzhi'))
req1 = opener.open(url_cmu, urllib.urlencode(body))
req1 = opener.open(url_login, urllib.urlencode(body))
response = urllib2.urlopen('https://cs.login.cmu.edu/idp/Authn/Stateless')
print response.read()
for line in cj:
    print line

#response = urllib2.urlopen('http://chenzongzhi.info/wp-admin/')
#print response.info()
#print response.read()
