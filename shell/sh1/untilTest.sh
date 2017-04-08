#!/bin/bash

echo "input the world, if the world = quit"

read world


until [ $world = "quit" ]
do
    echo $world
    read world
done

