#!/bin/bash

echo "input word, if word=quit, then quit the shell"
read word

while [ $word != "quit" ]
do 
    echo $word
    read word
done

exit 0
