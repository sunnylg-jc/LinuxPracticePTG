#!/bin/bash

if [ ! -f "data.txt" ]; then
	echo "File not Found!"
	exit 1
fi
	cat data.txt | while read line
	do
		echo "Fruit:[$line]"
	done
