#!/usr/bin/env python
# coding=utf-8

fibs = [0, 1]

num = input("input the numbers do you want? ")

for i in range(num-2):
    fibs.append(fibs[-1] + fibs[-2])

print fibs
