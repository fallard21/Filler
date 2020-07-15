#!/bin/bash

usage="usage: -g [map] [player1] [player2]\n"
key=0

if [ "$#" -eq 0 ]
then
	printf "$usage"
	exit
else
	for param in "$@"
	do
	if [ $param = "-g" ]
	then
		key=1
	fi
	done
fi

if [ $key -eq 1 ] && [ "$#" -eq 4 ]
then
	./filler_vm -f $2 -p1 $3 -p2 $4 | ../visualizer
elif [ $key -eq 0 ] && [ "$#" -eq 3 ]
then
	./filler_vm -f $1 -p1 $2 -p2 $3
else
	printf "$usage"
fi
