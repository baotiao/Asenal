#!/usr/bin/env python
import re
match = re.search(r'..g', 'piiig')
print 'fount', match.group(), match.groups()

match = re.search(r'<.*?>', '<b>foo<b>')
print match.group()


