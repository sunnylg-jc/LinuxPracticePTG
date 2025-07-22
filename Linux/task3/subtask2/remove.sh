#!/bin/bash

sed '9d' file1.txt > temp.txt
paste file1.txt temp.txt
rm temp.txt
