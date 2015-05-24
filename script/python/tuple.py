#!/usr/bin/env python 
parents, babies = (1, 1)
while babies < 100:
    print 'This has %d babies' % babies
    parents, babies = (babies, parents + babies)
