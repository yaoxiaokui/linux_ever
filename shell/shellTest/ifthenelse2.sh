#!/bin/bash


read filename

if [ -e $filename ]
then
    if [ -s $filename ];then
        echo "$filename size is bigger than 0"
    else
        echo "$filename size is less or equal than 0"
    fi
else
    echo "$filename is not exist"
fi

