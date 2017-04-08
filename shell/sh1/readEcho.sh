#!/bin/bash

myvar="Hi here"

echo $myvar
echo "$myvar"
echo '$myvar'
echo \$myvar

echo Enter some text
read myvar

echo '$myvar' now is $myvar

exit 0
