#!/usr/bin/env python
class MyClass:
    i = 12345
    def f(self):
        return 'hello world\n'

x = MyClass()
str = x.f()
print str
