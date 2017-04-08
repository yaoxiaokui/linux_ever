#!/usr/bin/env python
# coding=utf-8

def fibs(num):
    result = [0, 1]

    for i in range(num-2):
        result.append(result[-1] + result[-2])

    return result 

 
num = input("Input the num: ")
print fibs(num)
