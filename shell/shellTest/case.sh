#!/bin/bash


read num

case $num in
1) 
    echo "input 1"
    ;;
2) 
    echo "input 2"
    ;;

*)
    echo "input other"
    exit;
    ;;
esac
