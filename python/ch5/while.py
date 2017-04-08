#!/usr/bin/env python
# coding=utf-8
name = ''

while not name or name.isspace():
    name = raw_input("Please input your name:")
print 'Hello, %s!' % name
