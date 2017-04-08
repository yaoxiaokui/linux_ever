#!/bin/bash


echo "input the choice"
read word

case $word in
    yes)  echo "yes";;
    no)   echo "no";;
    *)    echo "other";;
esac
