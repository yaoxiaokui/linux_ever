#!/bin/bash

for file in *
do
    if grep -l POSIX $file
    then
        #echo $file
        more $file
    fi
done

exit 0
