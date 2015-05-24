#!/usr/bin/env python
import re
for test_string in ['555-1212', 'ILL-EGAL']:
    if re.match(r'^\d{3}-\d{4}$', test_string):
        print test_string, 'is a valis US number'
    else:
        print test_string, 'rejected'
