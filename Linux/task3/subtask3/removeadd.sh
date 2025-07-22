#!/bin/bash

sed '12d; 11a this is the new inserted line' file1.txt > temp.txt
paste file1.txt temp.txt
rm temp.txt
