#!/bin/bash


echo "is it morning? Please answer yes or no"
read timeofday

if [ $timeofday = "yes" ]
then
    echo "morning"
elif [ $timeofday = "no" ]
then
    echo "afternoon"
else
    echo "input error"
fi


