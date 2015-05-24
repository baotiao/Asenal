#!/usr/bin/env python
def second(word):
    return word[1]
words = ['ac', 'bb', 'ca']
#print sorted(words, key = second)
def tuple_zip(tuple):
    return tuple[0]
tu = {'beijing' : 2001, 'tianjin' : 3111, 'fuzhou' : 1231}
tt = tu
print tt
for iter,num in tu.iteritems():
    print iter, num
sorted(tu, key = tuple_zip)
print tu
