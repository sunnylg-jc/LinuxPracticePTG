#!/bin/bash

touch source.txt
touch destination.txt

src="source.txt"
dest="destination.txt"

if [ ! -f "$src" ]; then
	echo "File not found"
	exit 1
fi
	cp -p "$src" "$dest"
	echo "File copied with same properties and time stamp"
	echo ""
	echo "Lets check it"
	echo ""
	ls -l source.txt destination.txt
	
