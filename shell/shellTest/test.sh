#!/bin/bash

test -d 11

if [ $? -eq 0 ]
then
    echo "11 dir exist";
else
    echo "11 dir not exist";
fi
