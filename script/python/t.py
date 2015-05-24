#!/usr/bin/env python
# -*- coding: utf8 -*-
import time
print 'The time is:', time.time()
now = time.localtime()
print 'Now is ', now
print type(now)
print now.tm_year
